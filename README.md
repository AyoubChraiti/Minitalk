# Minitalk

## Into
+ Minitalk is a small data exchange program using UNIX signals.

## Features
- Signal-based messaging: Utilizes UNIX signals (SIGUSR1 and SIGUSR2) to transmit information.
- Minimalist design: Focuses on core functionalities to ensure simplicity and efficiency.
- Error handling: Implements basic error handling to manage signal interruptions or miscommunications.
## Getting Started
+ These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

## Prerequisites
Minitalk is designed to run on UNIX-like operating systems. It requires a C compiler (like gcc or clang / cc) and the make utility to build the project.

## Installing
- Clone the repository

- Start by cloning the Minitalk repository to your local machine:

```sh
git clone https://github.com/yourusername/minitalk.git
```
```sh
cd minitalk
```

- Build the project

- Compile the server and client programs using the make command:

```sh
make
```

- This will generate two executable files: server and client.

## Usage
To use Minitalk, start the server to listen for incoming messages, and then use the client to send messages to the server.

Start the server

Run the server program:

```sh
./server
```
Upon starting, the server will display its PID (Process ID). This PID is used by the client to send messages to the server.

- Send a message from the client

- In a new terminal window, use the client program to send a message to the server using its PID:
```sh
./client <Server_PID> "Your message here"

```
+ Replace <Server_PID> with the actual PID displayed by the server. The message you specify will be sent to the server and then echoed back to the console.