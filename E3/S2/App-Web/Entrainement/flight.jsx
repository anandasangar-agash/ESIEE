import * as React from 'react';
import * as ReactDOM from 'react-dom/client';

async function fetchFlights(setFlights, setCheapestId){
    setCheapestId(-1);
    const response = await fetch("/api/flights", {method : "GET"});
    if(!response.ok){
        throw new Error();
    }
    const data = await response.json();
    setFlights(data);
}

async function fetchDelete(id, flights, setFlights, setCheapestId){
    const response = await fetch(`/api/flights/${encodeURIComponent(id)}`, {method: "DELETE"});
    if(!response.ok){
        throw new Error();
    }
    const filteredFlights = flights.filter(i => i.id !== id);
    setCheapestId(-1);
    setFlights(filteredFlights);
}

function compareFlight(f1, f2) {
  if (f1.from < f2.from) {
    return -1;
  }
  if (f1.from > f2.from) {
    return 1;
  }
  return 0;
}

function toHour(minutes) {
  return `${Math.floor(minutes / 60)}h ${minutes % 60}m`;
}

function FlightRow({flight, flights, setFlights, cheapestId, setCheapestId}){
    const {id, from, to, duration, price} = flight;

    return <tr className={id === cheapestId ? "highlight" : "" }>
        <td>{from}</td>
        <td>{to}</td>
        <td>{toHour(duration)}</td>
        <td>${price}</td>
        <td><DeleteButton id={id} flights={flights} setFlights={setFlights} setCheapestId={setCheapestId}/></td>
    </tr>
}

function RefreshButton({setFlights, setCheapestId}){
    return <button onClick={async () => {await fetchFlights(setFlights, setCheapestId)}}>Refresh flights</button>
}

function getMinimumPrice(flights, setCheapestId){
    if(flights.length === 0){
        return;
    }
    let minPrice = flights[0].price;
    let minId = flights[0].id;
    for(let el of flights){
        const currentPrice = el.price;
        const currentId = el.id;
        if(currentPrice < minPrice){
            minPrice = currentPrice;
            minId = currentId;
        }
    }
    setCheapestId(minId);
}

function CheapestButton({flights, setCheapestId}){
    return <button onClick={() => {getMinimumPrice(flights, setCheapestId)}}>Cheapest flight</button>
}

function DeleteButton({id, flights, setFlights, setCheapestId}){
    return <button onClick={async () => {await fetchDelete(id, flights, setFlights, setCheapestId)}}>Delete</button>
}

function FlightList(){

    const [flights, setFlights] = React.useState([]);
    const [cheapestId, setCheapestId] = React.useState(-1);
    React.useEffect( () => {
        fetchFlights(setFlights, setCheapestId);
    }, []);
    return <>
        <div>
            <RefreshButton setFlights={setFlights} setCheapestId={setCheapestId}/>
            <CheapestButton flights={flights} setCheapestId={setCheapestId} />
        </div>
        <table>
        <thead>
            <tr>
                <th onClick={() => {flights.sort((a,b) => compareFlight(a,b))}}>From</th>
                <th>To</th>
                <th>Duration</th>
                <th>Price</th>
                <th>Action</th>
            </tr>
        </thead>
        <tbody>
            {flights.map(i => <FlightRow key={i.id} flight={i} flights={flights} setFlights={setFlights} cheapestId={cheapestId} setCheapestId={setCheapestId} />)}
        </tbody>
    </table>
    </>
}


function App() {
  return <div className="app">
    <FlightList />
  </div>;
}

window.onload = () => {
  const appDOM = document.getElementById("App");
  const root = ReactDOM.createRoot(appDOM);
  root.render(<App/>);
};
