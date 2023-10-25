-- -- Find description
-- SELECT description
-- FROM crime_scene_reports
-- WHERE month = 7 AND day = 28
-- AND street = "Humphrey Street";
-- -- 10:15 am, duck stolen, Humphrey street, 3 witnesses -> bakery

-- -- Find more detailed description
-- SELECT name, transcript
-- FROM interviews
-- WHERE year = 2021 AND month = 7 AND day = 28;
-- -- about 10 mins after theft left carpark, ATM Leggett Street,
-- -- less than 1 min phone call, earlyest flight 07 29 2021

-- FIND SUSPECT
SELECT DISTINCT name AS "Suspect"
FROM people
JOIN bakery_security_logs
ON bakery_security_logs.license_plate = people.license_plate
JOIN bank_accounts
ON bank_accounts.person_id = people.id
JOIN atm_transactions
ON atm_transactions.account_number = bank_accounts.account_number
JOIN phone_calls
ON phone_calls.caller = people.phone_number
JOIN passengers
ON passengers.passport_number = people.passport_number
JOIN flights
ON passengers.flight_id = flights.id
WHERE activity = "exit"
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw"
AND duration <= 60 AND atm_transactions.year = 2021
AND atm_transactions.day = 28 AND atm_transactions.month = 7
AND phone_calls.day =28 AND phone_calls.month = 7
AND phone_calls.year = 2021
AND bakery_security_logs.minute <= 25
AND bakery_security_logs.hour = 10
AND flights.id = (SELECT id FROM flights WHERE year= 2021 AND MONTH
= 7 AND day = 29 ORDER BY hour LIMIT 1);

-- FIND CITY ESCAPED TO
SELECT city
FROM airports
JOIN flights
ON flights.destination_airport_id = airports.id
WHERE flights.id = (SELECT id FROM flights WHERE year= 2021 AND MONTH
= 7 AND day = 29 ORDER BY hour LIMIT 1);

-- FIND ACCOMPLICE
SELECT name AS "Acomplice"
FROM phone_calls
JOIN people ON phone_calls.receiver = people.phone_number
WHERE year = 2021 AND month = 7 AND day = 28
AND duration <= 60 AND caller = (SELECT phone_number
FROM people
WHERE name = "Bruce");

