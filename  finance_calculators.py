import math

# Display menu and get user input
print("investment - to calculate the amount of interest you'll earn on your investment")
print("bond - to calculate the amount you'll have to pay on a home loan")
choice = input("Enter either 'investment' or 'bond' from the menu above to proceed: ")

# Convert user input to lowercase for easier comparison
choice = choice.lower()

# Check if user entered a valid choice
if choice == "investment":
    # Get user input for investment calculation
    deposit = float(input("Enter the amount of money that you are depositing: "))
    interest_rate = float(input("Enter the interest rate (as a percentage): ")) / 100
    years = float(input("Enter the number of years you plan on investing: "))
    interest = input("Do you want simple or compound interest? ").lower()
    
    # Calculate total amount based on interest type
    if interest == "simple":
        total = deposit * (1 + interest_rate * years)
    elif interest == "compound":
        total = deposit * math.pow((1 + interest_rate), years)
    else:
        # Invalid interest type entered
        print("Invalid input for interest type. Please enter 'simple' or 'compound'.")
        exit()
    
    # Print total amount
    print(f"The total amount you will get back after {years} years is: {total:.2f}")
    
elif choice == "bond":
    # Get user input for bond calculation
    present_value = float(input("Enter the present value of the house: "))
    annual_interest_rate = float(input("Enter the annual interest rate: ")) / 100
    monthly_interest_rate = annual_interest_rate / 12
    months = int(input("Enter the number of months over which the bond will be repaid: "))
    
    # Calculate bond repayment amount
    repayment = (monthly_interest_rate * present_value) / (1 - math.pow((1 + monthly_interest_rate), -months))
    
    # Print bond repayment amount
    print(f"The monthly repayment amount is: {repayment:.2f}")
    
else:
    # Invalid menu choice entered
    print("Invalid input. Please enter 'investment' or 'bond'.")
    exit()

