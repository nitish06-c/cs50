SELECT movies.title from people
JOIN stars on people.id = stars.person_id
JOIN movies on stars.movie_id = movies.id
JOIN ratings on movies.id = ratings.movie_id
WHERE people.name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;

