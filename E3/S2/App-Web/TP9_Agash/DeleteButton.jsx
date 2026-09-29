import React from 'react';  
import { useState } from "react";
import { deleteFlight } from "./api.js";

export function DeleteButton({ id, onDelete }) {
  
  async function handleClick() {
    try {
      await deleteFlight(id);
      onDelete(id);
    } catch (err) {
      alert(`Erreur lors de la suppression : ${err.message}`);
    }
  }

  return (
    <td>
      <button onClick={handleClick}>
        Delete
      </button>
    </td>
  );
}
