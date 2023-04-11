SELECT DISTINCT name
FROM people JOIN stars on people.id = stars.person_id
JOIN movies on movies.id = stars.movie_id
WHERE name != "Kevin Bacon"
AND movie_id IN (
    SELECT movie_id
    FROM people JOIN stars on people.id = stars.person_id
    WHERE name = "Kevin Bacon" AND birth = 1958
);