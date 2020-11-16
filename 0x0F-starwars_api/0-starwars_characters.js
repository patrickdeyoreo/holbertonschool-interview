#!/usr/bin/node
// Query the Starwars API for a list of characters from a given film

const request = require('request');

const api = 'https://swapi-api.hbtn.io/api/films/';

function getCharacterName (url) {
  return new Promise((resolve, reject) => {
    request.get(url, (error, response, body) => {
      if (error) {
        reject(error);
      } else {
        resolve(JSON.parse(body).name);
      }
    });
  });
}

function getFilmCharacters (url) {
  return new Promise((resolve, reject) => {
    request.get(url, (error, response, body) => {
      if (error) {
        reject(error);
      } else {
        resolve(JSON.parse(body).characters);
      }
    });
  });
}

getFilmCharacters(api + process.argv[2]).then((characters) => {
  Promise.all(characters.map(getCharacterName)).then((names) => {
    names.forEach(console.log);
  });
});
