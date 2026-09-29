import React from 'react';  

export function RefreshButton({ onRefresh }) {
  return (
    <button onClick={onRefresh}>
      Refresh Flights
    </button>
  );
}
