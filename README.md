# ksu-hackathon-2022
central repository for our work on the fall 2022 ksu hackathon

Big Picture: Clock in/out system built around facial recognition and RFID authentication.
  - RFID is the first step in authentication
    - Read badge
    - Create timestamp
    - Determine whether this is a clock in or a clock out
  - Facial recognition is the second step
    - Scan face
    - Determine identity
    - Deny clock in/out if RFID identity doesn't match face identity

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
