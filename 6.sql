SELECT AVG(rating) from ratings
JOIN movies on ratings.movie_id = movies.id
WHERE year = 2012;
