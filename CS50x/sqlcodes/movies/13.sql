-- 13. Names of all people who starred in a movie in which Kevin Bacon also starred
SELECT people.name FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE movies.id IN (
    SELECT movie_id FROM stars
    WHERE person_id = (SELECT id FROM people WHERE name = 'Kevin Bacon')
)
AND people.name != 'Kevin Bacon';
