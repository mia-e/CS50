SELECT title
FROM people JOIN stars on people.id = stars.person_id
JOIN movies on movies.id = stars.movie_id
JOIN ratings on movies.id = ratings.movie_id
WHERE name = "Chadwick Boseman"
ORDER BY rating DESC LIMIT 5;