temp_f = input('enter the temprature in degree fahrenheit: ');
temp_k = (5/9) * (temp_f - 32) + 273.15;
fprintf('%6.2f degree fahrenheit = %6.2f kelvin.\n',temp_f,temp_k);