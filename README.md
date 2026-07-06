
# Bank Management System (C++)

A simple console-based Bank Management System written in C++ using plain file I/O for persistence. Supports user signup/login, customer operations (balance check, deposit, withdraw) and basic admin functions (view, delete, change role).

## Features
- Signup and login for `user` and `admin` roles
- Persist users to `user.txt` (username, password, role, balance)
- User operations: check balance, deposit, withdraw, logout
- Admin operations: list users, delete user, change user role, logout

## Files of interest
- Source: [bank system/bank system/bank.cpp](bank%20system/bank%20system/bank.cpp#L1)
- Data: [bank system/bank system/user.txt](bank%20system/bank%20system/user.txt#L1)
- This README: [README.md](README.md#L1)

## Build & Run (Windows)
1. Install a C++ compiler (e.g. MinGW or MSYS2).
2. From the workspace root run:

```powershell
g++ -o Bank.exe "bank system/bank system/bank.cpp"
.
\Bank.exe
```