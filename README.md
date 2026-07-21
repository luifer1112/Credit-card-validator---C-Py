# Credit-card-validator---C-Py
# Credit Card Validation Algorithm (Luhn's Algorithm in C & Python)

## Description
This repository contains a dual-implementation of Luhn's Algorithm (Checksum Validation) used to verify the mathematical validity of credit card numbers and identify the issuing network (AMEX, VISA, or MASTERCARD). Developed as part of Harvard University's CS50x curriculum, the project explores credit card validation through low-level arithmetic extraction in C and string-to-integer mathematical operations in Python.

The implementation focuses on explicit mathematical manipulation—extracting individual digits using modular arithmetic and integer division without reliance on dynamic string abstraction loops—demonstrating a deep, fundamental understanding of digit positioning, memory layout, and checksum calculations.

## Validation Criteria & Brand Rules
* **AMEX:** 15 digits, starts with 34 or 37.
* **MASTERCARD:** 16 digits, starts with 51, 52, 53, 54, or 55.
* **VISA:** 13 or 16 digits, starts with 4.
* **Luhn's Checksum:**
  1. Multiply every second digit by 2, starting from the second-to-last digit.
  2. Add those products' digits together.
  3. Add the sum to the sum of the digits that were not multiplied by 2.
  4. If the total modulo 10 equals 0, the number is mathematically valid.

## Core Implementation Details
* **Explicit Positional Arithmetic:** Performs direct base-10 modulo (`%`) and integer division (`/` or `//`) operations to isolate digits at exact positional indices (`a` through `p`).
* **Digit Decomposition:** Deconstructs double-digit products resulting from Luhn's multiplication step into single-digit addends dynamically using modulo 10 and modulo 100 offsets.
* **Dual-Language Parity:** Implements symmetrical logic structures across both **C** (strongly typed, low-level execution) and **Python** (type-validated with Regular Expressions).

## Tech Stack
* **Languages:** C, Python 3
* **Libraries:** `cs50.h` / `cs50` module, `stdio.h`, `re` (Python Regex Module)
* **Concepts:** Luhn's Checksum Algorithm, Modular Arithmetic, Digits Isolation, Explicit Type Conversion, Flow Control.
