Prin operația de **unificare** a două numere naturale $a$ și $b$ înțelegem obținerea celui mai mare număr care se poate forma din cifrele distincte din scrierea numărului $a$ și cifrele distincte din scrierea numărului $b$. De exemplu, unificând $a = 727952$ cu $b = 92868$ vom obține numărul $99876522$, deoarece din $a$ vom utiliza cifrele $2, 5, 7, 9$, iar din $b$ cifrele $2, 6, 8, 9$. Cel mai mare număr pe care îl putem forma cu aceste cifre este $99876522$. 

Operația de unificare poate fi aplicată și pentru $k$ numere, respectând aceeași regulă: pentru fiecare număr din cele $k$ identificăm cifrele distincte care apar în scrierea lui, apoi determinăm cel mai mare număr care se poate forma utilizând toate aceste cifre. De exemplu, unificând numerele $112$, $223$ și $12334$ vom obține $43322211$.

Se dau două numere naturale, $n$ și $k$, și un șir de $n$ numere naturale $a_1, a_2, ..., a_n$.

# Cerințe

Determinați și afișați:
1. cel mai mare număr de exact $k$ cifre din șirul dat;
2. cel mai mare număr care poate fi obținut prin unificarea a două valori aflate pe poziții alăturate în șirul dat;
3. cel mai mare număr care se poate obține prin unificarea a $k$ valori aflate pe poziții consecutive în șirul dat.

# Date de intrare
Fișierul de intrare `unificare.in` conține pe prima linie un număr natural $C$, reprezentând cerința ce trebuie rezolvată ($1$, $2$ sau $3$), pe a doua linie $n$ și $k$, cu semnificația din enunț, iar pe a treia linie cei $n$ termeni ai șirului precizațîn ordinea din șir. Numerele aflate pe aceeași linie a fișierului sunt separate prin câte un spațiu.

# Date de ieșire
În fișierul de ieșire `unificare.out`:
* dacă $C = 1$, se va afișa pe prima linie cel mai mare număr de $k$ cifre din șirul dat;
* dacă $C = 2$, se va afișa pe prima linie cel mai mare număr obținut prin unificarea a două numere alăturate în șir;
* dacă $C = 3$, se va afișa pe prima linie valoarea maximă obținută prin unificarea a $k$ valori aflate pe poziții consecutive.

# Restricții și precizări

* $C \in \{1,2,3\}$; $1 \leq n \leq 100 \ 000$; $1 \leq k \leq n/2$;
* $0 \leq a_i \leq 100 \ 000 \ 000$, pentru oricare $1 \leq i \leq n$;
* Pentru $20$ de puncte, $C = 1$ și $k \leq 8$;
* Pentru $5$ puncte, $C = 2$ și $n = 2$;
* Pentru $10$ puncte, $C = 2$ și $0 \leq a_i \leq 9$, pentru oricare $1 \leq i \leq n$;
* Pentru $35$ de puncte, $C = 2$ și nu există restricții suplimentare;
* Pentru $15$ puncte, $C = 3$ și $k \leq 8$;
* Pentru $15$ puncte, $C = 3$ și $k \leq n / 2$.

# Exemplul 1

`unificare.in`
```
1
5 3
112 223 12334 561 289
```

`unificare.out`
```
561
```

## Explicație

$C = 1$, $n = 5$ și $k = 3$. În șir sunt $4$ numere care au exact $3$ cifre: $112$, $223$, $561$ și $289$, cel mai mare dintre ele fiind $561$.

# Exemplul 2

`unificare.in`
```
2
5 3
112 223 12334 561 289
```

`unificare.out`
```
6543211
```

## Explicație

$C = 2$, $n = 5$ și $k = 3$, nu utilizăm valoarea lui $k$ și unificând $a_3$ cu $a_4$ vom obține cea mai mare valoare: $6543211$.

# Exemplul 3

`unificare.in`
```
3
5 3
112 223 12334 561 289
```

`unificare.out`
```
9865432211
```

## Explicație

$C = 3$, $n = 5$ și $k = 3$. Cea mai mare valoare care se poate obține este $9865432211$ și o obținem unificând $a_3$ cu $a_4$ și cu $a_5$.

