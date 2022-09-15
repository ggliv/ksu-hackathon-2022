# ksu-hackathon-2022
central repository for our work on the fall 2022 ksu hackathon

Big Picture: Clock in/out system built around facial recognition and RFID authentication.
  - RFID is the first step in authentication
    - Read badge
    - Create timestamp
    - Determine whether this is a clock in or a clock out
	+ Use a counter -> resets after working day
	+ If count is 0 -> increase to 1 -> clock in
	+ If count is 1 -> increase to 2 -> clock out
	+ Omit the break time
  - Facial recognition is the second step
    - Scan face
    - Determine identity
	+ Insert into database based on the EmployeeID
    - Deny clock in/out if RFID identity doesn't match face identity
  - Setup a database management for the Employee
    - Has the clock in / clock out
    - Date
    - Notes
# TODO
  - Face model training component
  - Face model identification component
  - RFID component
  - Component integration
  - Containerization for portability
  - Physical integration
    - Raspberry Pi
    - RFID scanner
    - RFID cards
    - Raspi-compatible camera
