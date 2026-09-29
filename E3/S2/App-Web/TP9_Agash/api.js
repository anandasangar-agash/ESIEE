// api.js — toutes les fonctions qui communiquent avec le serveur

export async function fetchFlights() {
  const response = await fetch("/api/flights");
  if (!response.ok) {
    throw new Error(response.statusText);
  }
  return response.json();
}

export async function deleteFlight(id) {
  const response = await fetch(`/api/flights/${encodeURIComponent(id)}`, {
    method: "DELETE",
  });
  if (!response.ok) {
    throw new Error(response.statusText);
  }
}
