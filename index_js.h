R"(
const temp = document.getElementById('temp');
const humd = document.getElementById('humd');

function listen(url) {
  const evtSrc = new EventSource(url);
  evtSrc.addEventListener("update", (e) => {
    const data = JSON.parse(e.data);
    if(data.Temperature) temp.innerText = data.Temperature.state;
    if(data.Humidity) humd.innerText = data.Humidity.state;
  });
}

fetch("/events/sensors")
  .then(res => res.text())
  .then(url => listen(url));

)"
