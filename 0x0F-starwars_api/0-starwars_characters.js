#!/usr/bin/node
// Query the Starwars API for a list of characters from a given film

const request = require('request');

const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

request.get(url, (error, response, body) => {
  if (error) {
    console.error(error);
  } else {
    const film = JSON.parse(body);
    const characters = [];
    for (let i = 0; i < film.characters.length; i++) {
      characters[i] = new Promise((resolve, reject) => {
        request.get(film.characters[i], (error, response, body) => {
          if (error) {
            reject(error);
          } else {
            resolve(JSON.parse(body).name);
          }
        });
      });
    }
    Promise.all(characters).then((values) => {
      for (let i = 0; i < values.length; i++) {
        console.log(values[i]);
      }
    });
  }
});
