# Digital Inventory System - Installation Guide

## System Requirements
- Windows 10 or later (64-bit)
- At least 4GB RAM
- 200MB free disk space
- Qt runtime libraries (auto-included in installer)

## Installation Steps
1. Download the latest installer from the release page or provided setup file:
   - `digital_inventory_system_setup.exe`
2. Run the installer and follow the on-screen instructions.
   - Choose the installation folder (default: `C:\Program Files\DigitalInventorySystem\`).
   - A desktop shortcut will be created automatically.
3. Once installed, launch the application from:
   - Desktop shortcut, or
   - Start Menu → **Digital Inventory System**

## First-Time Setup
1. When you open the app for the first time, you need a **product file** (CSV or TXT).
   - Example format:
     ```
     Product ID,Name,Category,Quantity,Price
     101,Keyboard,Electronics,20,850.00
     102,Mouse,Electronics,35,400.00
     ```
2. Use **Load File** button to select your product file.
3. The system will read the file and display the products in the table.

## Features
- Add new products
- Delete existing products
- Search & filter items
- Stock In / Stock Out
- Calculate total inventory value
- Export inventory report to PDF

## Uninstallation
1. Go to **Control Panel → Programs and Features**.
2. Find **Digital Inventory System** in the list.
3. Click **Uninstall** and follow the prompts.
