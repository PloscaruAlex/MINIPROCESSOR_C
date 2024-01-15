	Primul lucru pe care trebuie sa il faca programul este sa decodifice instructiunile primite de la tastatura.
Le-am citit intr-o variabila int, dar aveam nevoie de reprezentarea in baza 2 a instruciunii, care nu incapea intr-un
int asa ca am facut-o intr-un vector. Apoi, fiecare element al vectorului reprezentand cate un bit, am decodificat 
vectorul conform enuntului, retinand operatiile in alt vector si afisand numarul de operatii, operatiile si dimensiunea
operanzilor.
	La task-ul 2 am calculat numarul de variabile de tip unsigned short de care aveam nevoie si am citit instructiunile
pentru operanzi intr-un vector. Apoi le-am transformat in baza 2, intr-o matrice, pe fiecare rand aflandu-se cate o 
instructiune pentru operanzi. Dupa aceea, conform dimensiunii cerute, am decodificat fiecare instructiune pentru a face rost
de operanzi si am calculat si afisat rezultatul.
	La task-ul 3, task bonus, am folosit acelasi rationament ca la task-ul 2, numai ca reprezentarea in baza 2 a
instructiunilor pentru operanzi am facut-o intr-un vector, fiecare instructiune binara fiind pusa la sfarsitul precendentei.
Am facut asta pentru a putea lucra cu dimensiunile "ciudate" ale operanzilor, desi acest rationament putea fi folosit si
pentru task-ul 2. La final am calculat si afisat rezultatul, fara respectarea ordinii operatiilor.