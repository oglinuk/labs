function add(a, b) {
    return a + b;
}

function subtract(a, b) {
    return a - b;
}

function multiply(a, b) {
    return a * b;
}

function divide(a, b) {
    return a / b;
}

function exponential(a, b) {
    return a ** b;
}

function modulus(a, b) {
    return a % b;
}

function increment(a) {
    return a++;
}

function decrement(a) {
    return a--;
}

document.getElementById("add").innerHTML = `1 + 2 = ${add(1, 2)}`;
document.getElementById("subtract").innerHTML = `3 - 4 = ${subtract(3, 4)}`;
document.getElementById("multiply").innerHTML = `5 * 6 = ${multiply(5, 6)}`;
document.getElementById("divide").innerHTML = `7 / 8 = ${divide(7, 8)}`;
document.getElementById("exponential").innerHTML = `9 ^ 10 = ${exponential(9, 10)}`;
document.getElementById("modulus").innerHTML = `11 % 12 = ${modulus(11, 12)}`;
document.getElementById("increment").innerHTML = `13 incremented = ${increment(13)}`;
document.getElementById("decrement").innerHTML = `14 decremented = ${decrement(14)}`;