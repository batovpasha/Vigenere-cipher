'use strict';

const readline = require('readline');

const readData = (fn) => {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });
  rl.question('Enter your key: ', (key) => {
    rl.question('Enter your alphabet: ', (alphabet) => {
      rl.question('Enter your message: ', (message) => {
        rl.close();
        fn(key, alphabet, message);
      });
    });
  });
};

const decipher = (cipher) => {
  const decipherMessage = [];
  for (const i in cipher) {
    const row = matrix[0].indexOf(base[i]);
    const column = matrix[row].indexOf(cipher[i]);
    decipherMessage.push(matrix[0][column]);
  }
  console.log(`deciphered message: ${decipherMessage.join('')}`);
};

const encryption = (message, matrix) => {
  const cipher = [];
  for (const i in message) {
    const column = matrix[0].indexOf(message[i]);
    const row = matrix[0].indexOf(base[i]);
    cipher.push(matrix[row][column]);
  }
  console.log(`cipher: ${cipher.join('')}`);
  decipher(cipher);
};

const matrix = [];

const createMatrix = (alphabet, message) => {
  const alphabetArr = alphabet.split('');
  matrix.push(alphabetArr.slice());
  for (let i = 1; i < alphabetArr.length; i++) {
    alphabetArr.push(alphabetArr[0]);
    alphabetArr.shift();
    matrix.push(alphabetArr.slice());
  }
  console.log(matrix);
  encryption(message, matrix);
};

const base = [];

const main = (key, alphabet, message) => {
  message.split('').forEach(item => {
    if (!alphabet.includes(item)) {
      throw new Error(`alphabet dont includes "${item}"`);
    }
  });
  const arr = key.split('');
  arr.forEach(item => {
    if (message.length > base.length) base.push(item);
    else return;
  });
  if (base.length < message.length) main(key, alphabet, message);
  else createMatrix(alphabet, message);
};

readData(main);
