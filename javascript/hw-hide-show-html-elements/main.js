function change() {
    let ele = document.getElementById('someId');
    let btn = document.getElementById('btn');
    if (ele.style.display != 'none') {
        ele.style.display = 'none'; // Hide the element
        btn.innerHTML = 'Show';
    } else {
        ele.style.display = 'block'; // Show the element
        btn.innerHTML = 'Hide';
    }
}