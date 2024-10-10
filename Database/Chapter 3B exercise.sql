LAB Group 3 Exercise 
-- remember to write ';' !

-- Find the student’s name, age, and address who are above 23 years old. 
select sName, sAge, sAddress 
from student
where sAge > 23;

-- Find the student’s name and ID who enrolled into SOF202 course. 
select sName, ID
from student
where student.ID = course.sID   -- need to join the foreign key and the primary key
and course.CID = 'SOF202';

-- Find all the instructor’s information who teach SOF108 course. 
select *
from instructor, course
where instructor.IID = course.IID
and course.CID = 'SOF108';
 
-- Find the location and the class timing of ‘Computer Arc’ course. 
select cLocation, cTiming
from class, course
where class.CID = course.CID
and course.cName = 'Computer Arc';

-- Who taught student Amanda? 
select instructor.name
from instructor, student, course
where instructor.IID = course.IID
and student.id = course.sID
and student.name = 'Amanda';

SELECT instructor.name
FROM instructor
JOIN course ON instructor.IID = course.IID
JOIN student ON student.ID = course.sID
WHERE student.name = 'Amanda';

 