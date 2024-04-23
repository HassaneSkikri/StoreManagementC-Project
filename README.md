# Store Management System

## Project Overview
This project is a Store Management System written in C++. It is designed to manage the stock of various products in a store. It includes features for adding, updating, and removing stock items, tracking sales, and managing customer information.


## File Structure
- `Alimentaire.cpp/h`: Defines the food items management functionality.
- `Article.cpp/h`: Contains the definition and implementation of the base article class.
- `Client.cpp/h`: Manages client information.
- `Date.cpp/h`: Handles date-related functions.
- `Electromenage.cpp/h`: Manages electronic products.
- `entete.h`: Common header file for global definitions.
- `Magasin.cpp/h`: Contains the logic for store management.
- `main.cpp`: The entry point of the application.
- `Vestimentaire.cpp/h`: Manages clothing items.

## Getting Started
### Prerequisites
- A C++ compiler (e.g., GCC, Clang, MSVC)
- Make (optional, for build automation)

### Compilation
To compile the project, navigate to the project directory and run the following command:

```bash
g++ -o StoreManagement main.cpp Alimentaire.cpp Article.cpp Client.cpp Date.cpp Electromenage.cpp Magasin.cpp Vestimentaire.cpp
