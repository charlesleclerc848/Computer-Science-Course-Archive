#include <iostream>
using namespace std;

// Base class Trip
class Trip {
protected:
    string destination;
    string travelDate;

public:
    // Parameterized constructor for Trip
    Trip(string dest, string date)
        : destination(dest), travelDate(date) {}

    // Function to display trip details
    void displayTrip() {
        cout << "Destination: " << destination << "\nTravel Date: " << travelDate << endl;
    }
};

// Derived class Transport from Trip
class Transport : public Trip {
protected:
    string transportType;
    string ticketNumber;

public:
    // Parameterized constructor for Transport
    Transport(string dest, string date, string type, string ticket)
        : Trip(dest, date), transportType(type), ticketNumber(ticket) {}

    // Function to display transport details
    void displayTransport() {
        displayTrip();
        cout << "Transport Type: " << transportType << "\nTicket Number: " << ticketNumber << endl;
    }
};

// Derived class Flight from Transport
class Flight : public Transport {
private:
    string seatNumber;
    string airline;
    double baggageWeight;  // actual baggage weight of the passenger
    const double baggageAllowed = 35.0; // allowed baggage weight in kg

public:
    // Parameterized constructor for Flight
    Flight(string dest, string date, string type, string ticket,
           string seat, string airlineName, double baggageW)
        : Transport(dest, date, type, ticket), seatNumber(seat), airline(airlineName), baggageWeight(baggageW) {}

    // Method to calculate baggage fees
    double calculateBaggageFee() {
        double excessWeight = baggageWeight - baggageAllowed;
        if (excessWeight > 0) {
            return excessWeight * 20.0; // $20 per kg for excess baggage
        } else {
            return 0.0; // No fee if within the allowance
        }
    }

    // Function to display flight details
    void displayFlight() {
        displayTransport();
        cout << "Seat Number: " << seatNumber << "\nAirline: " << airline
             << "\nBaggage Weight: " << baggageWeight << " kg" << endl;
        double baggageFee = calculateBaggageFee();
        if (baggageFee > 0) {
            cout << "Excess Baggage Fee: $" << baggageFee << endl;
        } else {
            cout << "No Excess Baggage Fee." << endl;
        }
    }
};

// Example usage
int main() {
    // Noman's flight details
    Flight nomanFlight("Paris", "2024-12-15", "Flight", "AF1234", "12A", "Air France", 40.0);

    // Display flight details and calculate baggage fee
    nomanFlight.displayFlight();

    return 0;
}

