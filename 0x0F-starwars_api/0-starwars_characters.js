#!/usr/bin/node
// Query the Starwars API for a list of characters from a given film

const request = require("request");
const process = require("process");

let url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`

request(url, function (error, response, body) {
  if (error) {
    console.error(error);
  } else if (response) {
    const film = JSON.parse(body);
    for (let i = 0; i < film.characters.length; i++) {
      request(film.characters[i], function (error, response, body) {
        if (error) {
          console.error(error);
        } else if (response) {
          console.log(JSON.parse(body)["name"]);
        }
      });
    }
  }
});
