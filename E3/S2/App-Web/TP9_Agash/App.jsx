import React from 'react';  
import { createRoot } from "react-dom/client";
import { FlightList } from "./FlightList.jsx";

function App() {
  return (
    <div className="app">
      <FlightList />
    </div>
  );
}

window.onload = () => {
  const appDOM = document.getElementById("App");
  const root = createRoot(appDOM);
  root.render(<App />);
};
