vector<string> s (n);
// ... считывание строк ...

// считаем все степени p, допустим, до 10000 - максимальной длины строк
const int p = 31;
vector<long long> p_pow (10000);
p_pow[0] = 1;
for (size_t i=1; i<p_pow.size(); ++i)
  p_pow[i] = p_pow[i-1] * p;

// считаем хэши от всех строк
// в массиве храним значение хэша и номер строки в массиве s
vector < pair<long long, int> > hashes (n);
for (int i=0; i<n; ++i)
{
  long long hash = 0;
  for (size_t j=0; j<s[i].length(); ++j)
    hash += (s[i][j] - 'a' + 1) * p_pow[j];
  hashes[i] = make_pair (hash, i);
}

// сортируем по хэшам
sort (hashes.begin(), hashes.end());

// выводим ответ
for (int i=0, group=0; i<n; ++i)
{
  if (i == 0 || hashes[i].first != hashes[i-1].first)
    cout << "\nGroup " << ++group << ":";
  cout << ' ' << hashes[i].second;
}