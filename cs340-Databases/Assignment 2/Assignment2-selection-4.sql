#1 Find all films with maximum length or minimum rental duration (compared to all other films). 
#In other words let L be the maximum film length, and let R be the minimum rental duration in the table film. You need to find all films that have length L or duration R or both length L and duration R.
#You just need to return attribute film id for this query.

SELECT film_id FROM film WHERE rental_duration = (SELECT MIN(rental_duration) FROM film) 
OR length = (SELECT MAX(length) FROM film); 


#2 We want to find out how many of each category of film ED CHASE has started in so return a table with category.name and the count
#of the number of films that ED was in which were in that category order by the category name ascending (Your query should return every category even if ED has been in no films in that category).

SELECT cat.name AS filmCategory, COUNT(film.name) AS filmCount 
FROM (SELECT category.name FROM category) AS cat
LEFT JOIN (SELECT category.name FROM category
INNER JOIN film_category ON film_category.category_id = category.category_id
INNER JOIN film ON film.film_id = film_category.film_id
INNER JOIN film_actor ON film.film_id = film_actor.film_id
INNER JOIN actor ON actor.actor_id = film_actor.actor_id
WHERE actor.first_name = 'ED' AND actor.last_name = 'CHASE'
) AS film ON cat.name = film.name
GROUP BY cat.name
ORDER BY cat.name;

#3 Find the first name, last name and total combined film length of Sci-Fi films for every actor
#That is the result should list the names of all of the actors(even if an actor has not been in any Sci-Fi films)and the total length of Sci-Fi films they have been in.


SELECT x.first_name, x.last_name, y.total
FROM (SELECT actor.first_name, actor.last_name, actor.actor_id FROM actor actor) AS x
LEFT JOIN (SELECT actor.first_name, actor.last_name, actor.actor_id, SUM( film.length ) AS total, cat.name
FROM actor actor, film_actor a1, film film, film_category f1, category cat
WHERE cat.category_id = f1.category_id AND f1.film_id = film.film_id
AND actor.actor_id = a1.actor_id AND a1.film_id = film.film_id AND cat.name =  'Sci-Fi'
GROUP BY actor.actor_id) AS y 
ON x.actor_id = y.actor_id;

#4 Find the first name and last name of all actors who have never been in a Sci-Fi film

SELECT actor.first_name, actor.last_name FROM actor actor
WHERE actor.actor_id NOT IN (SELECT actor.actor_id FROM film film
INNER JOIN film_category filmCat ON film.film_id = filmCat.film_id
INNER JOIN category cat ON filmCat.category_id = cat.category_id
INNER JOIN film_actor filmActor ON film.film_id = filmActor.film_id
INNER JOIN actor actor ON filmActor.actor_id = actor.actor_id
WHERE cat.name =  'Sci-Fi'
GROUP BY film.title);


#5 Find the film title of all films which feature both KIRSTEN PALTROW and WARREN NOLTE
#Order the results by title, descending (use ORDER BY title DESC at the end of the query)
#Warning, this is a tricky one and while the syntax is all things you know, you have to think oustide
#the box a bit to figure out how to get a table that shows pairs of actors in movies

SELECT f.title AS 'Title' FROM film f
INNER JOIN film_actor film1 ON film1.film_id = f.film_id
INNER JOIN actor actor1 ON actor1.actor_id = film1.actor_id
INNER JOIN film_actor film2 ON film2.film_id = f.film_id
INNER JOIN actor actor2 ON actor2.actor_id = film2.actor_id
WHERE actor1.first_name =  "KIRSTEN"
AND actor1.last_name =  "PALTROW"
AND actor2.first_name =  "WARREN"
AND actor2.last_name =  "NOLTE"
ORDER BY f.title DESC 




#Help from https://github.com/solomreb/cs340-assignment2/blob/master/assignment2-selection.sql
