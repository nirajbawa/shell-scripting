# Shell Scripting Basics

Shell scripting allows you to automate tasks, execute multiple commands sequentially, and interact with your system via scripts. Here’s a concise introduction to the basics of shell scripting.

---

## 1. What is Shell Scripting?  
A shell script is a program written for a command-line interpreter or "shell" (e.g., Bash, Zsh). It contains a series of commands to be executed by the shell, automating repetitive tasks.

---

## 2. Writing a Shell Script  
1. **Create a file:**  
   ```bash
   touch myscript.sh
   ```
2. **Make it executable:**  
   ```bash
   chmod +x myscript.sh
   ```
3. **Add the Shebang (#!):**  
   The shebang tells the system which interpreter to use (usually Bash).  
   ```bash
   #!/bin/bash
   ```
4. **Write the script (inside `myscript.sh`):**  
   ```bash
   #!/bin/bash
   echo "Hello, World!"
   ```
5. **Run the script:**  
   ```bash
   ./myscript.sh
   ```

---

## 3. Basic Commands  
- **Printing to the console:**  
  ```bash
  echo "Hello, Niraj!"
  ```

- **Variables:**  
  ```bash
  name="Niraj"
  echo "Your name is $name"
  ```

- **Reading user input:**  
  ```bash
  echo "Enter your age: "
  read age
  echo "You are $age years old"
  ```

---

## 4. Conditional Statements  
- **If-else:**  
  ```bash
  #!/bin/bash
  echo "Enter a number: "
  read num

  if [ $num -gt 10 ]; then
    echo "Number is greater than 10"
  else
    echo "Number is 10 or less"
  fi
  ```

---

### Arithmetic Operators  
Used for numerical operations with `expr` or `$((...))`.  
| Operator | Meaning            | Example                       | Output |
|----------|--------------------|-------------------------------|--------|
| +        | Addition           | `expr 5 + 3` or `$((5 + 3))`  | 8      |
| -        | Subtraction        | `expr 5 - 3` or `$((5 - 3))`  | 2      |
| \*       | Multiplication     | `expr 5 \* 3` or `$((5 * 3))` | 15     |
| /        | Division           | `expr 6 / 3` or `$((6 / 3))`  | 2      |
| %        | Modulus (remainder)| `expr 5 % 2` or `$((5 % 2))`  | 1      |

---

### Relational (Comparison) Operators  
Used to compare numbers.  

| Operator | Meaning             | Example        |
|----------|---------------------|----------------|
| -eq      | Equal to            | `[ 5 -eq 5 ]` |
| -ne      | Not equal to        | `[ 5 -ne 3 ]` |
| -lt      | Less than           | `[ 3 -lt 5 ]` |
| -le      | Less than or equal  | `[ 3 -le 5 ]` |
| -gt      | Greater than        | `[ 5 -gt 3 ]` |
| -ge      | Greater than or equal | `[ 5 -ge 5 ]` |

Example:
```bash
num=10
if [ $num -gt 5 ]; then
  echo "Greater than 5"
else
  echo "Less than or equal to 5"
fi
```

---

### Logical Operators  
| Operator | Meaning                     | Example                     |
|----------|-----------------------------|-----------------------------|
| `&&`     | Logical AND (both true)     | `[ $a -gt 5 ] && [ $b -lt 10 ]` |
| `!`      | Logical NOT (negation)      | `[ ! $a -eq 5 ]`            |

Example:
```bash
a=8
b=3
if [ $a -gt 5 ] && [ $b -lt 10 ]; then
  echo "Both conditions are true"
fi
```

---

### String Operators  
| Operator | Meaning             | Example                |
|----------|---------------------|------------------------|
| =        | Equal to            | `[ "$str1" = "$str2" ]` |
| !=       | Not equal to        | `[ "$str1" != "$str2" ]` |
| -z       | String is empty     | `[ -z "$str" ]`         |
| -n       | String is not empty | `[ -n "$str" ]`         |

Example:
```bash
str="Hello"
if [ -n "$str" ]; then
  echo "String is not empty"
fi
```

---

### File Test Operators  
| Operator | Meaning                       | Example                   |
|----------|-------------------------------|---------------------------|
| -e       | File exists                   | `[ -e myfile.txt ]`       |
| -f       | Exists and is a regular file  | `[ -f myfile.txt ]`       |
| -d       | Directory exists              | `[ -d mydir ]`            |
| -r       | File is readable              | `[ -r myfile.txt ]`       |
| -w       | File is writable              | `[ -w myfile.txt ]`       |
| -x       | File is executable            | `[ -x myfile.txt ]`       |

---

### Loops  
- **For loop:**  
  ```bash
  for i in {1..5}; do
    echo "Number: $i"
  done
  ```

- **While loop:**  
  ```bash
  counter=1
  while [ $counter -le 5 ]; do
    echo "Counter: $counter"
    ((counter++))
  done
  ```

---

### Functions  
```bash
#!/bin/bash

greet() {
  echo "Hello, $1!"
}

greet "Niraj"
```

---

### Useful Commands in Shell Scripts  
- **`date`:** Display the current date and time.  
  ```bash
  echo "Current date: $(date)"
  ```
- **`ls`:** List directory contents.  
  ```bash
  ls -l
  ```
- **`mkdir`:** Create a new directory.  
  ```bash
  mkdir new_folder
  ```
- **`grep`:** Search for patterns in a file.  
  ```bash
  grep "pattern" filename.txt
  ```

---

### Handling Arguments  
```bash
#!/bin/bash
echo "Script name: $0"
echo "First argument: $1"
echo "Second argument: $2"
```
Run it with:
```bash
./myscript.sh arg1 arg2
```

---

### Error Handling  
Use `set -e` to exit the script if any command fails:
```bash
#!/bin/bash
set -e
mkdir test_folder
cd test_folder || exit
```

---

### Scheduling Shell Scripts with Cron  
You can schedule shell scripts to run periodically using **cron**.  
Edit the crontab:
```bash
crontab -e
```
Add a cron job (e.g., run script every day at 5 PM):
```bash
0 17 * * * /path/to/myscript.sh
```

---

This document provides a comprehensive guide to **shell scripting basics**, covering key concepts, syntax, and practical examples.