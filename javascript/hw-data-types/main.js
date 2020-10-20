let x;
let y = 2;
let is = x == y;

document.getElementById("undefined").innerHTML = `Undefined: let x | ${typeof x}`;
document.getElementById("number").innerHTML = `Number: ${x = 5} | ${typeof x}`;
document.getElementById("string").innerHTML = `String: x = 'Bob'`;
document.getElementById("object").innerHTML = `Object: ${x = { firstName: 'Elliot', lastName: 'Alderson' }} | ${typeof x}`;
document.getElementById("number_with_decimals").innerHTML = `Number with decimals: ${x = 42.00} | ${typeof x}`;
document.getElementById("scientific_notation").innerHTML = `Scientific notation (4e-2): ${x = 4e-2} | ${typeof x}`;
document.getElementById("boolean").innerHTML = `Boolean (let y = 2; x == y): ${x == y} | ${typeof is}`;
document.getElementById("array").innerHTML = `Array: ${x = [1, 2, 3]} | ${typeof x}`;
document.getElementById("null").innerHTML = `Null: ${x = null} | ${typeof x}`;