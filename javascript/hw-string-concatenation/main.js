function concatenate() {
    let first = document.getElementById('first').innerHTML;
    let second = document.getElementById('second').innerHTML;
    let concatenated = `${first} ${second}`; // A cleaner way to concatenate than first + ' ' + second
    document.getElementById('concatenated').innerHTML = `Concatenated: ${concatenated}`;
}