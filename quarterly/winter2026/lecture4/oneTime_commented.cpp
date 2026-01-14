#include <iostream>
#include <cstring>
using namespace std;


// and
// | p | q | p & q |
// | T | T | T     |
// | T | F | F     |
// | F | T | F     |
// | F | F | F     |
// or
// | p | q | p | q |
// | T | T | T     |
// | T | F | T     |
// | F | T | T     |
// | F | F | F     |
// xor
// | p | q | p ^ q |
// | 1 | 1 | 0     |
// | 1 | 0 | 1     |
// | 0 | 1 | 1     |
// | 0 | 0 | 0     |


// the idea of the 1-time pad is that you
// take a message and a key
// the key MUST BE THE SAME LENGTH AS THE MESSAGE
// and you xor the bytes of the key and the message
// together one by one
//
// Why XOR?
// - XOR is reversible: (m ^ k) ^ k == m
// - If the key is truly random and used once, the ciphertext reveals
//   no information about the plaintext (perfect secrecy).
// - Reusing a key breaks the security: (m1 ^ k) ^ (m2 ^ k) == m1 ^ m2.
//
// Important constraints for a real one-time pad:
// - Key length equals message length.
// - Key is random, uniformly distributed.
// - Key is used exactly once and kept secret.
//
// This demo focuses on the XOR mechanics with ASCII chars stored in C-strings.
// It does NOT enforce key length or randomness; the user is trusted to comply.

int main(){

  // C-strings are null-terminated arrays of char; here we reserve 100 bytes.
  char msg[100];
  cout << "Enter the message to read: " << endl;
  cin.getline(msg,100);

  // We'll store the XORed result here; same max length as msg.
  char encrypted[100];

  cout << "Enter the key (must be " << strlen(msg) << ") characters in length: " << endl;
  // Read the key as another C-string. User must match msg length.
  char key[100];
  cin.getline(key,100);

  cout << "Encrypted message: " << endl;
  // Encrypt: XOR each message byte with the corresponding key byte.
  // We stop at the null terminator of msg, so the key should be at least
  // that long (same length for proper one-time pad use).
  int i=0;
  while(msg[i] != '\0'){
    // XOR each byte of the message with the corresponding key byte.
    encrypted[i] = key[i] ^ msg[i];
    i++;
  }
  encrypted[i] = '\0';

  // Print the encrypted bytes as integers so they are visible.
  // XORed data may include non-printable characters.
  i=0;
  while(encrypted[i] != '\0'){
    cout << (int)encrypted[i] << " ";
    i++;
  }
  cout << endl;

  // Decrypt: XOR with the same key again to recover the original.
  // This works because XOR cancels itself out.
  i = 0;
  while(encrypted[i] != '\0'){
    encrypted[i] = encrypted[i] ^ key[i];
    i++;
  }

  cout << "Unencrypted: " << encrypted << endl;


  return 0;
}
