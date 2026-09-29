import * as React from 'react';
import * as ReactDOM from 'react-dom/client';

function App() {
  return <div className="app">
    <FlightList />
  </div>;
}

async function fetchFlights(setFlights){
    const response = await fetch("/api/flights");
    if (!response.ok) {
        throw new Error(response.statusText);
    }
    const flights = await response.json();
    setFlights(flights);
}

function toHour(minutes) {
  return `${Math.floor(minutes / 60)}h ${minutes % 60}m`;
}

function FlightList(){

    const[flights, setFlights] = React.useState([]);
    const [cheapestId, setCheapestId] = React.useState(null);

    React.useEffect(() => {fetchFlights(setFlights);}, []);

    async function loadFlights() {
        setCheapestId(null);
        await fetchFlights(setFlights);
    }

    React.useEffect(() => { loadFlights(); }, []);

    function handleDelete(id) {
        setCheapestId(null);
        setFlights((prev) => prev.filter((f) => f.id !== id));
    }

    return (
        <div>
            <div>
                <RefreshButton onRefresh={loadFlights} />
                <CheapestButton flights={flights} onHighlight={setCheapestId} />
            </div>
            <table>
                <thead>
                    <tr>
                        <th>From</th>
                        <th>To</th>
                        <th>Duration</th>
                        <th>Price</th>
                        <th>Action</th>
                    </tr>
                </thead>
                <tbody>
                    {flights.map(flight => 
                        <tr key={flight.id} className={flight.id === cheapestId ? "highlight" : ""}>
                            <td>{flight.from}</td>
                            <td>{flight.to}</td>
                            <td>{toHour(flight.duration)}</td>
                            <td>${flight.price}</td>
                            <DeleteButton id={flight.id} onDelete={handleDelete}/>
                        </tr>
                    )}
                </tbody>
            </table>
        </div>
    );
}

async function deleteFlight(id){
    const response = await fetch(`/api/flights/${encodeURIComponent(id)}`, {
        method : "DELETE"
    });
    if (!response.ok) {
        throw new Error(response.statusText);
    }
}

function DeleteButton({ id, onDelete }) {
    const [loading, setLoading] = React.useState(false);

    async function handleClick() {
        setLoading(true);
        try {
            await deleteFlight(id);
            onDelete(id);
        } catch (err) {
            alert(`Erreur : ${err.message}`);
        } finally {
            setLoading(false);
        }
    }

    return (
        <td>
        <button onClick={handleClick} disabled={loading}>
            Delete
        </button>
        </td>
    );
}

function RefreshButton({ onRefresh }) {
    return <button onClick={onRefresh}>Refresh Flights</button>;
}

function CheapestButton({ flights, onHighlight }) {
    function handleClick() {
        if (flights.length === 0) {
            alert("Aucun vol disponible !");
            return;
        }
        const cheapest = flights.reduce(
            (min, flight) => (flight.price < min.price ? flight : min),
            flights[0]
        );
        onHighlight(cheapest.id);
    }

    return <button onClick={handleClick}>Cheapest Flight</button>;
}

window.onload = () => {
  const appDOM = document.getElementById("App");
  const root = ReactDOM.createRoot(appDOM);
  root.render(<App/>);
};