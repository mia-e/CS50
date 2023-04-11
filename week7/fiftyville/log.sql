-- Keep a log of any SQL queries you execute as you solve the mystery.


SELECT description FROM crime_scene_reports
WHERE day = 28 AND month = 7;

SELECT year FROM crime_scene_reports
WHERE description LIKE "%CS50%";


SELECT license_plate FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10;

SELECT license_plate, activity, minute FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10;

SELECT name, transcript FROM interviews
 WHERE year = 2021 AND month = 7 AND day = 28;


SELECT name FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
WHERE day = 28 AND month = 7 AND year = 2021
AND atm_location = "Leggett Street";               ,

SELECT, name, reciever FROM phone_calls
JOIN people ON phone_calls.phone


SELECT hour, minute, city, flights.id FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
WHERE day = 29 AND month = 7 AND year = 2021;


SELECT name FROM flights
   ...> JOIN passengers ON flights.id = passengers.flight_id
   ...> JOIN people ON passengers.passport_number = people.passport_number
   ...> WHERE flights.id = 36;

   SELECT city FROM flights
JOIN airports ON flights.destination_airport_id = airports.id
WHERE flights.id = 36;

   SELECT name FROM people
   WHERE phone_number = "(375) 555-8161";
