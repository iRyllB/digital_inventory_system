# ADRIAN MOLIJON
# HENNA PAJO


import datetime


inventory = {}
purchases = []



def add_item(name, batch_number, expiry_date, quantity, price):
    expiry_date = datetime.datetime.strptime(expiry_date, "%Y-%m-%d").date()
    if name in inventory:
        inventory[name].append({
            'batch_number': batch_number,
            'expiry_date': expiry_date,
            'quantity': quantity,
            'price': price
        })
    else:
        inventory[name] = [{
            'batch_number': batch_number,
            'expiry_date': expiry_date,
            'quantity': quantity,
            'price': price
        }]


def sell_item(name, quantity):
    if name not in inventory:
        print(f"Item {name} not found.")
        return None

    remaining_qty = quantity
    inventory[name] = sorted(inventory[name], key=lambda x: x['expiry_date'])

    for batch in inventory[name]:
        if batch['expiry_date'] < datetime.date.today():
            continue
        if batch['quantity'] >= remaining_qty:
            batch['quantity'] -= remaining_qty
            purchase_details = {
                'name': name,
                'quantity': quantity,
                'price': batch['price'],
                'expiry_date': batch['expiry_date']
            }
            purchases.append(purchase_details)
            remaining_qty = 0
            if batch['quantity'] == 0:
                inventory[name].remove(batch)
            break
        else:
            purchase_details = {
                'name': name,
                'quantity': batch['quantity'],
                'price': batch['price'],
                'expiry_date': batch['expiry_date']
            }
            purchases.append(purchase_details)
            remaining_qty -= batch['quantity']
            inventory[name].remove(batch)

    if remaining_qty > 0:
        print(f"Only {quantity - remaining_qty} of {name} was sold due to limited stock.")
        return purchase_details
    else:
        print(f"Sold {quantity} of {name}.")
        return purchase_details


def edit_item():
    check_inventory()
    name = input("Enter the name of the medicine you want to edit: ").capitalize()
    if name not in inventory:
        print(f"Item {name} not found in inventory.")
        return

    print("Current details:")
    for i, batch in enumerate(inventory[name]):
        print(f"{i+1}. Batch: {batch['batch_number']}, Expiry: {batch['expiry_date']}, Quantity: {batch['quantity']}, Price: ₱{batch['price']}")

    choice = input("Enter the number of the batch you want to edit: ")
    try:
        index = int(choice) - 1
        if 0 <= index < len(inventory[name]):
            batch = inventory[name][index]
            quantity = int(input("Enter new quantity: "))
            price = float(input("Enter new price per unit: "))
            batch['quantity'] += quantity
            batch['price'] = price
            print(f"Item {name}, Batch: {batch['batch_number']} updated successfully.")
        else:
            print("Invalid batch number.")
    except ValueError:
        print("Invalid input. Please enter a number.")



def add_new_item():
    while True:
        name = input("Enter the name of the medicine: ").capitalize()
        if not name:
            print("Please enter the name of the medicine.")
            continue

        batch_number = input("Enter batch number (ex. A213): ")
        if not batch_number:
            print("Please enter the batch number.")
            continue

        expiry_date = input("Enter expiry date (YYYY-MM-DD): ")
        if not expiry_date:
            print("Please enter the expiry date.")
            continue

        quantity_str = input("Enter quantity: ")
        if not quantity_str.isdigit():
            print("Please enter a valid quantity.")
            continue
        quantity = int(quantity_str)

        price_str = input("Enter price per unit: ")
        if not price_str.replace('.', '', 1).isdigit():  
            print("Please enter a valid price.")
            continue
        price = float(price_str)

        add_item(name, batch_number, expiry_date, quantity, price)
        print(f"Item {name} added to inventory successfully.")
        break



def check_inventory():
    print("Current Inventory:")
    for name, batches in inventory.items():
        for batch in batches:
            print(
                f"Name: {name}, Price: ₱{batch['price']}, Batch: {batch['batch_number']}, Expiry: {batch['expiry_date']}, Quantity: {batch['quantity']}")



def inventory_alerts(threshold: object = 10) -> object:
    low_stock_items = []
    expired_items = []

    for name, batches in inventory.items():
        for batch in batches:
            if batch['quantity'] <= threshold:
                low_stock_items.append((name, batch['quantity']))
            if batch['expiry_date'] < datetime.date.today():
                expired_items.append((name, batch['expiry_date']))

    if low_stock_items:
        print("Low stock items:")
        for item in low_stock_items:
            print(f"Name: {item[0]}, Quantity: {item[1]}")

    if expired_items:
        print("Expired items:")
        for item in expired_items:
            print(f"Name: {item[0]}, Expiry Date: {item[1]}")

def remove_expired_items():
    expired_items = []
    for name, batches in inventory.items():
        for batch in batches:
            if batch['expiry_date'] < datetime.date.today():
                expired_items.append((name, batch))

    for name, batch in expired_items:
        inventory[name].remove(batch)
        print(f"Removed expired item: {name}, Batch: {batch['batch_number']}, Expiry: {batch['expiry_date']}")


def print_receipt(purchase_details=None):
    if purchase_details:
        print("\n--- Receipt ---")
        print(
            f"Name: {purchase_details['name']} \nQuantity: {purchase_details['quantity']} \nPrice: ₱{purchase_details['price']:.2f} each \nExpiry Date: {purchase_details['expiry_date']}")
        total_cost = purchase_details['quantity'] * purchase_details['price']
        print("————————————————————————————")
        print(f"Total Cost: ₱{total_cost:.2f}")
        print("————————————————————————————")
        print("\n--- Receipt ---")
    else:
        print("No items purchased.")


def customer_order():
    while True:
        print("\nWelcome to the Pharmacy ")
        print("1. Order Medicine")
        print("2. Edit Item")
        print("3. Check Inventory")
        print("4. Check Alerts")
        print("5. Exit")

        choice = input("Enter your choice: ").lower()  

        if choice == '1':
            check_inventory()
            name = input("Enter the name of the medicine: ").capitalize()  
            quantity = int(input("Enter the quantity: "))
            purchase_details = sell_item(name, quantity)
            if purchase_details:
                print("Your order has been placed successfully.")
                print_receipt(purchase_details)

        elif choice == '2':
            print("\nChoose what would you like to do:")
            print("1. Edit Item")
            print("2. Add Item")
            print("3. Delete Item")
            print("4. Exit")

            choose = input("What would you like to do: ")

            if choose == '1':
                edit_item()
            elif choose == '2':
                add_new_item()
            elif choose == '3':
                remove_expired_items()
            elif choose == '4':
                break
            else:
                print("Invalid Choice:")

        elif choice == '3':
            check_inventory()

        elif choice == '4':
            inventory_alerts()

        elif choice == '5':
            print("Thank you for using our service:")
            print_receipt
            break

        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
   
    add_item("Aspirin", "A123", "2025-05-17", 100, 5.99)
    add_item("Ibuprofen", "B456", "2024-07-19", 50, 7.49)
    add_item("Cetirizine", "C789", "2023-11-30", 30, 5.99)

    
customer_order()

