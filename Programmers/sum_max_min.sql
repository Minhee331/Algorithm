--최댓값 구하기
SELECT MAX(DATETIME) from ANIMAL_INS

--최솟값 구하기
SELECT MIN(DATETIME) from ANIMAL_INS

--동물 수 구하기
SELECT COUNT(*) from ANIMAL_INS

--중복 제거하기
SELECT count(distinct name) from ANIMAL_INS