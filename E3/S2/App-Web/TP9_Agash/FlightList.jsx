// FlightList.jsx
import React, { useState, useEffect } from "react";
import { fetchFlights } from "./api.js";
import { DeleteButton } from "./DeleteButton.jsx";
import { RefreshButton } from "./RefreshButton.jsx";
import { CheapestButton } from "./CheapestButton.jsx";

function toHour(minutes) {
  return `${Math.floor(minutes / 60)}h ${minutes % 60}m`;
}

export function FlightList() {
  const [flights, setFlights] = useState([]);
  const [cheapestId, setCheapestId] = useState(null);
  const [sortKey, setSortKey] = useState(null);

  async function loadFlights() {
    setCheapestId(null);
    const data = await fetchFlights();
    setFlights(data);
  }

  useEffect(() => { loadFlights(); }, []);

  function handleDelete(id) {
    setCheapestId(null);
    setFlights((prev) => prev.filter((f) => f.id !== id));
  }

  function handleSort(key) {
    setSortKey(key);
  }

  const displayedFlights = sortKey
    ? [...flights].sort((f1, f2) => {
        if (f1[sortKey] < f2[sortKey]) return -1;
        if (f1[sortKey] > f2[sortKey]) return 1;
        return 0;
      })
    : flights;

  const columns = [
    { key: "from",     label: "From" },
    { key: "to",       label: "To" },
    { key: "duration", label: "Duration" },
    { key: "price",    label: "Price" },
  ];

  return (
    <div>
      <div>
        <RefreshButton onRefresh={loadFlights} />
        <CheapestButton flights={displayedFlights} onHighlight={setCheapestId} />
      </div>
      <table>
        <thead>
          <tr>
            {columns.map(col => 
              <th
                key={col.key}
                className={sortKey === col.key ? "sort" : ""}
                onClick={() => handleSort(col.key)}
              >
                {col.label}
              </th>
            )}
            <th>Action</th>
          </tr>
        </thead>
        <tbody>
          {displayedFlights.map(flight => 
            <tr
              key={flight.id}
              className={String(flight.id) === String(cheapestId) ? "highlight" : ""}
            >
              <td>{flight.from}</td>
              <td>{flight.to}</td>
              <td>{toHour(flight.duration)}</td>
              <td>${flight.price}</td>
              <DeleteButton id={flight.id} onDelete={handleDelete} />
            </tr>
          )}
        </tbody>
      </table>
    </div>
  );
}