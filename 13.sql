SELECT distinct(name) from people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.title IN(SELECT DISTINCT(movies.title) FROM people
JOIN stars ON people.id =  stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE people.name = "Kevin Bacon" and people.birth = 1958)
AND people.name != "Kevin Bacon"
