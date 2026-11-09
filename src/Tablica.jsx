// function App() {
//   return (
//     <table border="1">
//       <tbody>
//         <tr>
//           <td>1</td>
//           <td>2</td>
//           <td>3</td>
//         </tr>
//         <tr>
//           <td>4</td>
//           <td>5</td>
//           <td>6</td>
//         </tr>
//         <tr>
//           <td>7</td>
//           <td>8</td>
//           <td>9</td>
//         </tr>
//       </tbody>
//     </table>
//   );
// }



function Tablica() {
  const osoba = {
  imie: "Jan",
  wiek: 25,
  miasto: "Warszawa",
  zawod: "Programista"
}
  
  return (
    <div>
      <h2>{osoba.imie}</h2>
      <p>Wiek: {osoba.wiek}</p>
      <p>Miasto: {osoba.miasto}</p>
      <p>Zawód: {osoba.zawod}</p>
    </div>
  )
}
  

export default Tablica;