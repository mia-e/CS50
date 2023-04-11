SELECT title
FROM people JOIN stars on people.id = stars.person_id
JOIN movies on movies.id = stars.movie_id
WHERE name = "Johnny Depp"
and movie_id IN (
    SELECT movie_id
    FROM people JOIN stars on people.id = stars.person_id
    WHERE name = "Helena Bonham Carter"
)
