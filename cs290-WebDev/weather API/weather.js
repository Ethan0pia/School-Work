/*******************************************************************************************
**Author: Ethan
**Date: 5/10/17
**assignment: weather
**discription: This program sends a get request to open weather API and displays it's contents
*******************************************************************************************/

    document.getElementById('submitButton').addEventListener('click', function (event) {
        var city = document.getElementById('cityEnter').value;
        var req = new XMLHttpRequest();
        req.open("GET", "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&units=imperial&appid=fa7d80c48643dfadde2cced1b1be6ca1", true);
        req.addEventListener('load', function () {
            if (req.status >= 200 && req.status < 400) {
                var response = JSON.parse(req.responseText);
                document.getElementById('city').textContent = response.name;
                document.getElementById('temp').textContent = response.main.temp;
                document.getElementById('humid').textContent = response.main.humidity;
            } else {
                console.log("Error in network request: " + req.statusText);
            }
        });
        req.send(null);
        event.preventDefault();
    })

    document.getElementById('submitPost').addEventListener('click', function (event) {
        var req2 = new XMLHttpRequest();
        var form = { "name": null};
        form.name = document.getElementById('text_input').value;
        console.log(JSON.stringify(form));

        req2.open('POST', 'http://httpbin.org/post', true);
        req2.setRequestHeader('Content-Type', 'application/json');
        req2.addEventListener('load', function () {
            if (req2.status >= 200 && req2.status < 400) {
                var response2 = JSON.parse(req2.responseText);

                document.getElementById('return1').textContent = response2.json.name;
            } else {
                console.log("Error in network request: " + req2.statusText);
            }
        });
        req2.send(JSON.stringify(form));
        event.preventDefault();
    });