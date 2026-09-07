-- Keep a log of any SQL queries you execute as you solve the mystery.
-- .tables
-- .schema table_name

--let's Start with Airports
SELECT * FROM airports WHERE city = 'Fiftyville';
-- 8|CSF|Fiftyville Regional Airport|Fiftyville => airport of fiftyville
--now let's go to crime scene reports
SELECT * FROM crime_scene_reports;
SELECT * FROM crime_scene_reports where street = 'Humphrey Street';
-- 295|2025|7|28|Humphrey Street|Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time
-- each of their interview transcripts mentions the bakery

--proceeding to people table to find out more about the witnesses
SELECT * FROM people;
--found nothing in people table,now proceeding to next table atm_transcations
SELECT * FROM atm_transactions WHERE atm_location = 'Leggett Street' and day=28 and month=7;
-- cannot infer details from this right now moving onto next

--in flights table
SELECT * FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
WHERE month=7 and city='Fiftyville' and day=28;

--1|8|7|2025|7|28|17|50|8|CSF|Fiftyville Regional Airport|Fiftyville
--6|8|5|2025|7|28|13|49|8|CSF|Fiftyville Regional Airport|Fiftyville
--17|8|4|2025|7|28|20|16|8|CSF|Fiftyville Regional Airport|Fiftyville
--34|8|5|2025|7|28|17|20|8|CSF|Fiftyville Regional Airport|Fiftyville
--35|8|4|2025|7|28|16|16|8|CSF|Fiftyville Regional Airport|Fiftyville

--yeah did'nt much to infer from this moving onto next phone calls table
SELECT * FROM phone_calls WHERE day=28 and month=7;
-- too much data to infer anything from this, moving onto next table bakery_security_logs
SELECT * FROM bakery_security_logs WHERE day=28 and month=7 and hour=10;
-- yeah again too much to digest now going to interviews to finally infer something
SELECT * FROM interviews WHERE day=28 and month=7;
--161|Ruth|2025|7|28|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. 
--If you have security footage from the bakery parking lot,
--you might want to look for cars that left the parking lot in that time frame.

--162|Eugene|2025|7|28|I don't know the thief's name, but it was someone I recognized. 
--Earlier this morning, before I arrived at Emma's bakery, 
--I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

--163|Raymond|2025|7|28|As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
--In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. 
--The thief then asked the person on the other end of the phone to purchase the flight ticket.

--ok finally some info
--so now we go back to prevous tables to find more info about the thief

--firstly we know that that theif left at about 10:25 acc to ruth so we can check the bakery security logs for that time frame
SELECT * FROM bakery_security_logs WHERE day=28 and month=7 and hour=10 and minute BETWEEN 15 AND 30;
--260|2025|7|28|10|16|exit|5P2BI95
--261|2025|7|28|10|18|exit|94KL13X
--262|2025|7|28|10|18|exit|6P58WS2
--263|2025|7|28|10|19|exit|4328GD8
--264|2025|7|28|10|20|exit|G412CB7
--265|2025|7|28|10|21|exit|L93JTIZ
--266|2025|7|28|10|23|exit|322W7JE
--267|2025|7|28|10|23|exit|0NTHK55

--so suspect someone from this license plate
--now lets check atm transactions for early morning withdrawals acc to eugene's statement
SELECT * FROM atm_transactions WHERE atm_location = 'Humphrey Lane' and day=28 and month=7 and transaction_type='withdraw';
-- alot of people have withdrawn money at 28/7 so we need to infer more from other tables

--now acc to raymond the theif talked to someone in between 10:15 and 10:25 for less then a minute
--and he also said that the thief was planning to take the earliest flight out of fiftyville tomorrow

--so now lets check the flights table for the earliest flight out of fiftyville on 29/7 and call_logs

SELECT * FROM phone_calls WHERE day=28 and month=7 and duration<60;
--221|(130) 555-0289|(996) 555-8899|2025|7|28|51
--224|(499) 555-9472|(892) 555-8872|2025|7|28|36
--233|(367) 555-5533|(375) 555-8161|2025|7|28|45
--251|(499) 555-9472|(717) 555-1342|2025|7|28|50
--254|(286) 555-6063|(676) 555-6554|2025|7|28|43
--255|(770) 555-1861|(725) 555-3243|2025|7|28|49
--261|(031) 555-6622|(910) 555-3251|2025|7|28|38
--279|(826) 555-1652|(066) 555-9701|2025|7|28|55
--281|(338) 555-6650|(704) 555-2131|2025|7|28|54

-- all the calls in less than a min so now lets check the flights table for the earliest flight out of fiftyville on 29/7
SELECT * FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
WHERE month=7 and day=29 and city='Fiftyville' and hour BETWEEN 0 AND 8;

--36|8|4|2025|7|29|8|20|8|CSF|Fiftyville Regional Airport|Fiftyville **
-- now we have the theif's destination airport id sowe can check the flights table for the destination airport id to find out where the thief is going

--now since we did the full  interviews we can now move to next table to find out more about the thief

--nope found nothing from bank_accounts table so now moving onto last table passenger

SELECT * FROM passengers
JOIN flights ON passengers.flight_id = flights.id
WHERE flights.id = 36;

--36|7214083635|2A|36|8|4|2025|7|29|8|20
--36|1695452385|3B|36|8|4|2025|7|29|8|20
--36|5773159633|4A|36|8|4|2025|7|29|8|20
--36|1540955065|5C|36|8|4|2025|7|29|8|20
--36|8294398571|6C|36|8|4|2025|7|29|8|20
--36|1988161715|6D|36|8|4|2025|7|29|8|20
--36|9878712108|7A|36|8|4|2025|7|29|8|20
--36|8496433585|7B|36|8|4|2025|7|29|8|20

-- so now we have the theif's passport no. and phone no. and license plate so we can check people table now 
SELECT * FROM people WHERE passport_number IN (7214083635, 1695452385, 5773159633, 1540955065, 8294398571, 1988161715, 9878712108, 8496433585) 
and phone_number IN ('(130) 555-0289', '(499) 555-9472', '(367) 555-5533', '(286) 555-6063', '(770) 555-1861', '(031) 555-6622', '(826) 555-1652', '(338) 555-6650')
and license_plate IN ('5P2BI95','94KL13X','6P58WS2','4328GD8','G412CB7','L93JTIZ','322W7JE','0NTHK55');

-- these are the suspects acc to the info
--1. sofia    398010|Sofia|(130) 555-0289|1695452385|G412CB7
--2. kelsey   560886|Kelsey|(499) 555-9472|8294398571|0NTHK55
--3. bruce    686048|Bruce|(367) 555-5533|5773159633|94KL13X

--these 3 are the ones who whose passports phone_number and license plate match with theif's 
--so now lets identify the theif from these suspects

--going to bakery_security_logs table
SELECT * FROM bakery_security_logs WHERE license_plate IN ('G412CB7','0NTHK55','94KL13X');
--232|2025|7|28|8|23|entrance|94KL13X
--243|2025|7|28|8|42|entrance|0NTHK55
--261|2025|7|28|10|18|exit|94KL13X
--267|2025|7|28|10|23|exit|0NTHK55

--from this data we can infer that sofia cannot be the theif as she did not leave between 10:15 to 10:25
--so its either kelsey or bruce

SELECT * FROM phone_calls WHERE caller IN('(367) 555-5533' , '(499) 555-9472') and day=28 and month=7 and duration<60;

--224|(499) 555-9472|(892) 555-8872|2025|7|28|36
--233|(367) 555-5533|(375) 555-8161|2025|7|28|45
--251|(499) 555-9472|(717) 555-1342|2025|7|28|50

--from here we can infer the accompliance
--no let's find theif's destination

SELECT *FROM passengers
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON flights.destination_airport_id = airports.id
WHERE passport_number IN ('8294398571','5773159633');

--36|5773159633|4A|36|8|4|2025|7|29|8|20|4|LGA|LaGuardia Airport|New York City
--36|8294398571|6C|36|8|4|2025|7|29|8|20|4|LGA|LaGuardia Airport|New York City

--so we have found out theif's destination it is LaGuardia Airport New York City

--now we identify the theif
SELECT * FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
WHERE name IN ('bruce' , 'kelsey');

--49610011|686048|2010|686048|Bruce|(367) 555-5533|5773159633|94KL13X
--"hence bruce is the culprit"
-- remember from earlier we had accompliance phone no .

--224|(499) 555-9472|(892) 555-8872|2025|7|28|36
--233|(367) 555-5533|(375) 555-8161|2025|7|28|45  => bruce
--251|(499) 555-9472|(717) 555-1342|2025|7|28|50

--here acc to bruce's phone no. the accompliance phone no. is (375) 555-8161

SELECT * FROM people WHERE phone_number LIKE '(375) 555-8161';

--864400|Robin|(375) 555-8161||4V16VO0

--so the accompliance name is robin

--so here are the results
-- culprit : bruce
-- accompliance : robin
-- destination : LaGuardia Airport New York City