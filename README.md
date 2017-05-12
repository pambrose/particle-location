# Particle Cell Tower GPS Notes

* Get a Google geolocation API key from [here](https://developers.google.com/maps/documentation/geolocation/get-api-key).

* Make sure you *enable* the Geolocation API in the Google API Manager section of the Console.

* The Goole geolocation API is described [here](https://developers.google.com/maps/documentation/geolocation/intro).

Install the particle CLI with:
```bash
$ npm install -g particle-cli
$ particle login
```

Download new firmware from the particle IDE and install it with:
```bash
$ particle flash --serial firmware.bin
```