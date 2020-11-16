#!/usr/bin/node
// Query the Starwars API for a list of characters from a given film

const request = require('request');

const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

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

getFilmCharacters(url).then((characters) => {
  for (let i = 0; i < characters.length; i++) {
    characters[i] = getCharacterName(characters[i]);
  }
  Promise.all(characters).then((names) => {
    for (let i = 0; i < names.length; i++) {
      console.log(names[i]);
    }
  });
});
