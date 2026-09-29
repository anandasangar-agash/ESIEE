import React from 'react';  

export function CheapestButton({ flights, onHighlight }) {
  function handleClick() {
    if (flights.length === 0) {
      alert("Aucun vol à afficher !");
      return;
    }
   
    const cheapest = flights.reduce(
      (min, flight) => (flight.price < min.price ? flight : min),
      flights[0]
    );
    onHighlight(cheapest.id);
  }

  return (
    <button onClick={handleClick}>
      Cheapest Flight
    </button>
  );
}
