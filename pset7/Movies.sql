--In 1.sql, write a SQL query to list the titles of all movies released in 2008.
SELECT title FROM movies WHERE year=2008;

--In 2.sql, write a SQL query to determine the birth year of Emma Stone.
SELECT birth FROM people WHERE name = 'Emma Stone';

--In 3.sql, write a SQL query to list the titles of all movies with a release date on or after 2018, in alphabetical order.
SELECT title FROM movies WHERE year>=2018 ORDER BY title ASC;

--In 4.sql, write a SQL query to determine the number of movies with an IMDb rating of 10.0.
SELECT COUNT(rating) FROM ratings WHERE rating=10.0;

--In 5.sql, write a SQL query to list the titles and release years of all Harry Potter movies, in chronological order.
SELECT title,year FROM movies WHERE title LIKE 'Harry Potter%' ORDER BY year ASC;

--In 6.sql, write a SQL query to determine the average rating of all movies released in 2012.
SELECT AVG(rating) FROM ratings JOIN movies ON movies.id =ratings.movie_id WHERE movies.year=2012;

--In 7.sql, write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
SELECT movies.title,ratings.rating FROM movies JOIN ratings ON ratings.movie_id=movies.id WHERE movies.year=2008 ORDER BY ratings.rating DESC,movies.title ASC;

--In 8.sql, write a SQL query to list the names of all people who starred in Toy Story.
SELECT name FROM people JOIN stars ON stars.person_id=people.id 
JOIN movies ON stars.movie_id=movies.id WHERE movies.title="Toy Story";

--In 9.sql, write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
SELECT DISTINCT(name) FROM people 
JOIN stars ON stars.person_id=people.id
JOIN movies ON movies.id=stars.movie_id
WHERE movies.year=2004 ORDER BY people.birth;

--In 10.sql, write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
SELECT name FROM people
JOIN directors ON directors.person_id=people.id JOIN movies ON directors.movie_id=movies.id
JOIN ratings ON ratings.movie_id=movies.id WHERE ratings.rating >= 9;

--In 11.sql, write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
SELECT title FROM movies
JOIN stars ON stars.movie_id=movies.id
JOIN people ON people.id=stars.person_id
JOIN ratings ON ratings.movie_id=movies.id
WHERE people.name='Chadwick Boseman' ORDER BY rating DESC LIMIT 5;

--In 12.sql, write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
SELECT title FROM movies
JOIN stars ON stars.movie_id=movies.id
JOIN people ON stars.person_id=people.id
WHERE people.name="Johnny Depp" AND title IN (
SELECT title FROM movies
JOIN stars ON stars.movie_id=movies.id
JOIN people ON stars.person_id=people.id
WHERE people.name="Helena Bonham Carter"
);

--In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
SELECT DISTINCT(name) FROM people
JOIN stars ON stars.person_id=people.id
JOIN movies ON stars.movie_id=movies.id
WHERE movies.id IN
(
SELECT movies.id FROM movies
JOIN stars ON stars.movie_id=movies.id
JOIN people ON stars.person_id=people.id
WHERE people.name="Kevin Bacon" AND people.birth=1958
)
AND people.name != "Kevin Bacon";
