# Die Mandelbrot-Menge: Von Null auf Visualisierung

## 1. Was sind komplexe Zahlen?

### 1.1 Die imaginäre Einheit

Normale Zahlen (reelle Zahlen) kennen wir alle: 1, 2, 3.5, -7, π usw. Diese liegen alle auf einem eindimensionalen Zahlenstrahl.

Komplexe Zahlen erweitern dieses Konzept in die zweite Dimension. Der Trick: Wir erfinden eine neue Zahl namens **i** (die imaginäre Einheit) mit der Eigenschaft:

```
i² = -1
```

Das ist zunächst verwirrend, weil keine normale Zahl diese Eigenschaft hat (sowohl 2² = 4 als auch (-2)² = 4). Aber mathematisch können wir mit **i** genauso rechnen wie mit normalen Zahlen.

### 1.2 Aufbau komplexer Zahlen

Eine komplexe Zahl besteht aus zwei Teilen:

```
z = a + bi
```

- **a** = Realteil (eine normale Zahl)
- **b** = Imaginärteil (auch eine normale Zahl)
- **i** = die imaginäre Einheit

**Beispiele:**
- `3 + 4i` → Realteil: 3, Imaginärteil: 4
- `2 - 5i` → Realteil: 2, Imaginärteil: -5
- `7 + 0i = 7` → eine rein reelle Zahl
- `0 + 3i = 3i` → eine rein imaginäre Zahl

### 1.3 Visualisierung: Die komplexe Ebene

Statt einem Zahlenstrahl verwenden wir eine Ebene:
- **x-Achse (horizontal)**: Realteil
- **y-Achse (vertikal)**: Imaginärteil

Die Zahl `3 + 4i` liegt also am Punkt (3, 4) in dieser Ebene.

```
    Imaginärteil (y)
         ↑
       5 |
       4 |     • (3+4i)
       3 |
       2 |
       1 |
       0 |-------|-------|→ Realteil (x)
      -1 |       2       4
      -2 |
```

### 1.4 Rechnen mit komplexen Zahlen

#### Addition
Einfach: Addiere Real- und Imaginärteile getrennt.

```
(a + bi) + (c + di) = (a + c) + (b + d)i
```

**Beispiel:**
```
(3 + 4i) + (1 + 2i) = (3+1) + (4+2)i = 4 + 6i
```

#### Multiplikation
Hier wird's interessanter. Wir multiplizieren wie bei Klammern, aber beachten dass **i² = -1**:

```
(a + bi) × (c + di) = ac + adi + bci + bdi²
                     = ac + adi + bci + bd(-1)
                     = (ac - bd) + (ad + bc)i
```

**Beispiel:**
```
(3 + 4i) × (1 + 2i) = 3×1 + 3×2i + 4i×1 + 4i×2i
                     = 3 + 6i + 4i + 8i²
                     = 3 + 10i + 8×(-1)
                     = 3 + 10i - 8
                     = -5 + 10i
```

#### Spezialfall: Quadrieren
Besonders wichtig für die Mandelbrot-Menge ist das Quadrieren:

```
(a + bi)² = (a + bi) × (a + bi)
          = a² + abi + abi + (bi)²
          = a² + 2abi + b²i²
          = a² + 2abi - b²
          = (a² - b²) + 2abi
```

**Merke dir diese Formel:**
```
(a + bi)² = (a² - b²) + (2ab)i
```

**Beispiel:**
```
(3 + 4i)² = (3² - 4²) + (2×3×4)i
          = (9 - 16) + 24i
          = -7 + 24i
```

### 1.5 Betrag (Abstand vom Ursprung)

Der Betrag einer komplexen Zahl ist ihr Abstand vom Ursprung (0, 0). Mit dem Satz des Pythagoras:

```
|a + bi| = √(a² + b²)
```

**Beispiel:**
```
|3 + 4i| = √(3² + 4²) = √(9 + 16) = √25 = 5
```

In der Ebene visualisiert ist das die Länge des Pfeils vom Ursprung zum Punkt (3, 4).

---

## 2. Die Mandelbrot-Iteration

### 2.1 Die Grundidee

Die Mandelbrot-Menge ist eine Menge von komplexen Zahlen **c**, die eine bestimmte Eigenschaft haben.

Für jede komplexe Zahl **c** führen wir folgende Iteration durch:

```
z₀ = 0
z₁ = z₀² + c = 0² + c = c
z₂ = z₁² + c
z₃ = z₂² + c
z₄ = z₃² + c
...
```

**Die Frage:** Bleibt die Folge z₀, z₁, z₂, z₃, ... beschränkt (in der Nähe des Ursprungs), oder explodiert sie gegen unendlich?

**Definition:** Die Zahl **c** gehört zur Mandelbrot-Menge, wenn die Folge beschränkt bleibt (nicht gegen unendlich geht).

### 2.2 Beispiel 1: c = 0

```
z₀ = 0
z₁ = 0² + 0 = 0
z₂ = 0² + 0 = 0
z₃ = 0² + 0 = 0
...
```

Die Folge bleibt bei 0. **c = 0 gehört zur Mandelbrot-Menge.**

### 2.3 Beispiel 2: c = 1

```
z₀ = 0
z₁ = 0² + 1 = 1
z₂ = 1² + 1 = 2
z₃ = 2² + 1 = 5
z₄ = 5² + 1 = 26
z₅ = 26² + 1 = 677
...
```

Die Folge explodiert! **c = 1 gehört NICHT zur Mandelbrot-Menge.**

### 2.4 Beispiel 3: c = -1

```
z₀ = 0
z₁ = 0² + (-1) = -1
z₂ = (-1)² + (-1) = 1 - 1 = 0
z₃ = 0² + (-1) = -1
z₄ = (-1)² + (-1) = 0
...
```

Die Folge springt zwischen -1 und 0 hin und her. Sie bleibt beschränkt. **c = -1 gehört zur Mandelbrot-Menge.**

### 2.5 Beispiel 4: c = i (eine komplexe Zahl!)

```
z₀ = 0
z₁ = 0² + i = i
z₂ = i² + i = -1 + i
z₃ = (-1 + i)² + i
```

Berechnen wir z₃ mit unserer Quadrierformel (a=-1, b=1):
```
(-1 + i)² = ((-1)² - 1²) + (2×(-1)×1)i
          = (1 - 1) + (-2)i
          = -2i

z₃ = -2i + i = -i
```

Weiter:
```
z₄ = (-i)² + i = (0 + (-1)i)² + i
   = (0² - (-1)²) + (2×0×(-1))i + i
   = -1 + 0i + i
   = -1 + i
```

Moment! z₄ = z₂. Die Folge wiederholt sich jetzt:
```
z₂ = -1 + i
z₃ = -i
z₄ = -1 + i
z₅ = -i
...
```

Die Folge bleibt beschränkt (pendelt zwischen zwei Werten). **c = i gehört zur Mandelbrot-Menge.**

---

## 3. Der Algorithmus zur Visualisierung

### 3.1 Warum nicht unendlich lange testen?

Wir können nicht unendlich viele Iterationen durchführen. Daher verwenden wir zwei Abbruchkriterien:

**Kriterium 1: Divergenz erkannt**
Mathematisch bewiesen: Wenn der Betrag von z jemals größer als 2 wird (|z| > 2), dann wird die Folge definitiv gegen unendlich gehen.

Da |z| = √(real² + imag²) ist, können wir stattdessen prüfen:
```
real² + imag² > 4
```
(Das spart die Wurzelberechnung, weil 2² = 4)

**Kriterium 2: Maximale Iterationen**
Wir setzen eine Obergrenze, z.B. 100 oder 1000 Iterationen. Wenn wir diese erreichen ohne Divergenz, nehmen wir an, dass c zur Menge gehört.

### 3.2 Der Pseudocode

Für jede komplexe Zahl c = (c_real, c_imag):

```
z_real = 0
z_imag = 0
iteration = 0
max_iterations = 1000

solange (iteration < max_iterations):
    // Berechne z² + c
    z_real_neu = z_real² - z_imag² + c_real
    z_imag_neu = 2 × z_real × z_imag + c_imag
    
    z_real = z_real_neu
    z_imag = z_imag_neu
    
    // Divergenz-Check
    wenn (z_real² + z_imag² > 4):
        break  // Divergenz erkannt!
    
    iteration = iteration + 1

// Ergebnis: iteration
// - Wenn iteration = max_iterations: c ist in der Menge (schwarz färben)
// - Sonst: c ist außerhalb (Farbe basierend auf iteration)
```

### 3.3 Wichtige Details zur Implementierung

**1. Reihenfolge der Berechnung**

```cpp
// FALSCH:
z_real = z_real * z_real - z_imag * z_imag + c_real;
z_imag = 2 * z_real * z_imag + c_imag;  // Nutzt bereits das neue z_real!
```

```cpp
// RICHTIG:
double z_real_neu = z_real * z_real - z_imag * z_imag + c_real;
double z_imag_neu = 2 * z_real * z_imag + c_imag;
z_real = z_real_neu;
z_imag = z_imag_neu;
```

**2. Optimierung der Divergenz-Prüfung**

```cpp
// Berechne die Quadrate nur einmal:
double z_real_squared = z_real * z_real;
double z_imag_squared = z_imag * z_imag;

double z_real_neu = z_real_squared - z_imag_squared + c_real;
double z_imag_neu = 2 * z_real * z_imag + c_imag;

// Divergenz-Check
if (z_real_squared + z_imag_squared > 4.0) {
    break;
}
```

---

## 4. Von Pixeln zur komplexen Ebene

### 4.1 Das Problem

Dein Bildschirm hat Pixel mit Koordinaten:
- x: 0 bis fenster_breite (z.B. 0 bis 800)
- y: 0 bis fenster_hoehe (z.B. 0 bis 600)

Die interessante Region der Mandelbrot-Menge liegt bei:
- Real-Achse: ungefähr -2.5 bis +1.0
- Imaginär-Achse: ungefähr -1.0 bis +1.0

Wir müssen jeden Pixel auf einen Punkt in der komplexen Ebene abbilden.

### 4.2 Die Mapping-Formel

#### Schritt 1: Normalisiere Pixelkoordinaten auf [0, 1]

```
x_normiert = x / fenster_breite      // Wert zwischen 0 und 1
y_normiert = y / fenster_hoehe       // Wert zwischen 0 und 1
```

#### Schritt 2: Skaliere auf den gewünschten Bereich

```
c_real = min_real + x_normiert × (max_real - min_real)
c_imag = min_imag + y_normiert × (max_imag - min_imag)
```

#### Beispiel mit konkreten Zahlen

Angenommen:
- Fenster: 800×600 Pixel
- Bereich: real [-2.5, 1.0], imaginär [-1.0, 1.0]

Für Pixel (400, 300) (die Fenstermitte):

```
x_normiert = 400 / 800 = 0.5
y_normiert = 300 / 600 = 0.5

c_real = -2.5 + 0.5 × (1.0 - (-2.5))
       = -2.5 + 0.5 × 3.5
       = -2.5 + 1.75
       = -0.75

c_imag = -1.0 + 0.5 × (1.0 - (-1.0))
       = -1.0 + 0.5 × 2.0
       = -1.0 + 1.0
       = 0.0
```

Die Fenstermitte entspricht also der komplexen Zahl c = -0.75 + 0i.

### 4.3 Koordinatensysteme beachten

**Problem:** In den meisten Grafiksystemen ist y=0 oben und y wächst nach unten. In der Mathematik wächst die imaginäre Achse nach oben.

**Lösung 1:** Y-Koordinate umdrehen
```
y_normiert = 1.0 - (y / fenster_hoehe)
```

**Lösung 2:** min_imag und max_imag vertauschen
```
c_imag = max_imag - y_normiert × (max_imag - min_imag)
```

Beide führen zum gleichen Ergebnis: Die Mandelbrot-Menge wird richtig herum angezeigt.

### 4.4 Seitenverhältnis (Aspect Ratio)

Wenn dein Fenster nicht quadratisch ist, musst du aufpassen, dass Kreise nicht zu Ellipsen werden.

**Option 1:** Passe den Bereich an das Fensterverhältnis an

```
aspect_ratio = fenster_breite / fenster_hoehe

real_span = max_real - min_real
imag_span = max_imag - min_imag

// Zentriere und passe an
center_real = (min_real + max_real) / 2
center_imag = (min_imag + max_imag) / 2

if (aspect_ratio > 1.0) {
    // Fenster ist breiter als hoch → erweitere Real-Achse
    half_span = imag_span * aspect_ratio / 2
    min_real = center_real - half_span
    max_real = center_real + half_span
} else {
    // Fenster ist höher als breit → erweitere Imaginär-Achse
    half_span = real_span / aspect_ratio / 2
    min_imag = center_imag - half_span
    max_imag = center_imag + half_span
}
```

**Option 2:** Rendere in ein quadratisches Bild und zeige es zentriert im Fenster

---

## 5. Färbung und Visualisierung

### 5.1 Basis-Färbung

Das Einfachste:
- **In der Menge** (max_iterations erreicht): Schwarz
- **Außerhalb**: Färbung basierend auf der Iterationszahl

```
if (iteration == max_iterations) {
    farbe = SCHWARZ
} else {
    // iteration geht von 0 bis max_iterations-1
    helligkeitswert = iteration / max_iterations
    farbe = helligkeitswert  // z.B. 0 = schwarz, 1 = weiß
}
```

### 5.2 Farb-Paletten

Statt Graustufen kannst du Farbverläufe verwenden:

**Linear mapping:**
```
farbindex = (iteration × 256) / max_iterations
farbe = farbpalette[farbindex]
```

**Beliebte Paletten:**
- Regenbogen (HSV mit variierendem Hue)
- Blau-Violett-Verlauf
- Feuer (Schwarz → Rot → Orange → Gelb → Weiß)

### 5.3 Smooth Coloring (kontinuierliche Färbung)

Problem: Mit der einfachen Methode sieht man harte "Bänder" zwischen den Iterationsstufen.

Lösung: Nutze den finalen Betragswert für eine feinere Färbung:

```
wenn divergiert:
    // Wie stark über der Grenze sind wir?
    betrag_quadrat = z_real² + z_imag²
    
    // Smooth iteration count
    smooth_iteration = iteration + 1 - log(log(betrag_quadrat) / log(2)) / log(2)
    
    // Nutze smooth_iteration für Färbung
```

Das ergibt sanfte Farbverläufe ohne Bänder. (Dies ist mathematisch etwas fortgeschritten, aber das Ergebnis sieht viel besser aus.)

---

## 6. Zoom und Navigation

### 6.1 Zoom implementieren

Beim Zoomen verkleinerst du den sichtbaren Bereich der komplexen Ebene.

**Zoom um einen Faktor:**
```
zoom_factor = 2.0  // 2x näher heran

center_real = (min_real + max_real) / 2
center_imag = (min_imag + max_imag) / 2

span_real = (max_real - min_real) / zoom_factor
span_imag = (max_imag - min_imag) / zoom_factor

min_real = center_real - span_real / 2
max_real = center_real + span_real / 2
min_imag = center_imag - span_imag / 2
max_imag = center_imag + span_imag / 2
```

### 6.2 Zoom auf Mausposition

Wenn der User auf Pixel (mouse_x, mouse_y) klickt:

```
// Berechne die komplexe Zahl an der Mausposition
mouse_real = min_real + (mouse_x / fenster_breite) × (max_real - min_real)
mouse_imag = min_imag + (mouse_y / fenster_hoehe) × (max_imag - min_imag)

// Zentriere auf diese Position und zoome
span_real = (max_real - min_real) / zoom_factor
span_imag = (max_imag - min_imag) / zoom_factor

min_real = mouse_real - span_real / 2
max_real = mouse_real + span_real / 2
min_imag = mouse_imag - span_imag / 2
max_imag = mouse_imag + span_imag / 2
```

### 6.3 Interaktive Navigation

**Pan (Verschieben):**
```
verschiebung_real = delta_x / fenster_breite × (max_real - min_real)
verschiebung_imag = delta_y / fenster_hoehe × (max_imag - min_imag)

min_real -= verschiebung_real
max_real -= verschiebung_real
min_imag -= verschiebung_imag
max_imag -= verschiebung_imag
```

---

## 7. Performance-Optimierungen

### 7.1 Frühe Abbrüche

**Periodizitätsprüfung:** Speichere z in regelmäßigen Abständen. Wenn z sich wiederholt, bist du in einem Zyklus → in der Menge.

**Hauptkardioiden-Test:** Der große "Körper" der Mandelbrot-Menge (eine Kardioidform) kann analytisch getestet werden:

```
// Teste ob c in der Hauptkardioide liegt
q = (c_real - 0.25)² + c_imag²
if (q × (q + (c_real - 0.25)) < 0.25 × c_imag²) {
    // In der Hauptkardioide → direkt als "in der Menge" werten
    return max_iterations
}

// Teste ob c im Periode-2-Bulb liegt
if ((c_real + 1)² + c_imag² < 0.0625) {
    // Im Bulb → in der Menge
    return max_iterations
}
```

### 7.2 Symmetrie nutzen

Die Mandelbrot-Menge ist symmetrisch zur reellen Achse:
- Wenn (a + bi) in der Menge ist, dann auch (a - bi)

Du kannst nur die obere Hälfte berechnen und spiegeln.

### 7.3 Multi-Threading

Jeder Pixel kann unabhängig berechnet werden → perfekt für Parallelisierung!

Teile das Bild in Streifen oder Kacheln auf und berechne diese in verschiedenen Threads.

---

## 8. Interessante Koordinaten zum Erkunden

### Klassische Ansicht (Gesamtüberblick)
```
Real: [-2.5, 1.0]
Imag: [-1.25, 1.25]
```

### Seepferdchen-Tal
```
Real: [-0.75, -0.735]
Imag: [0.1, 0.115]
max_iterations: 500+
```

### Spiralen
```
Real: [-0.7, -0.65]
Imag: [0.4, 0.45]
max_iterations: 1000+
```

### Mini-Mandelbrot
```
Real: [-0.16, -0.14]
Imag: [1.025, 1.045]
max_iterations: 2000+
```

**Tipp:** Je tiefer du zoomst, desto höher sollte max_iterations sein, um Details zu sehen!

---

## 9. Häufige Fehler und deren Lösung

### 9.1 "Ich sehe nur Schwarz oder nur Weiß"

**Ursachen:**
- max_iterations zu niedrig oder zu hoch
- Koordinatenbereich außerhalb der interessanten Region
- Mapping-Formel falsch

**Lösung:** Beginne mit der klassischen Ansicht und max_iterations = 100.

### 9.2 "Das Bild ist verzerrt"

**Ursache:** Seitenverhältnis nicht korrekt berücksichtigt.

**Lösung:** Siehe Abschnitt 4.4 zur Aspect Ratio.

### 9.3 "Die Iteration zählt falsch"

**Ursache:** Du verwendest das neue z_real bei der Berechnung von z_imag_neu.

**Lösung:** Speichere beide neue Werte in temporären Variablen.

### 9.4 "Beim Zoomen wird das Bild unscharf"

**Ursache:** Bei tiefen Zoom-Stufen reicht die Präzision von `double` nicht mehr aus.

**Lösung:** 
- Nutze höhere Präzision (z.B. `long double`)
- Für extreme Zooms: arbitrary-precision Bibliotheken (GMP, MPFR)

### 9.5 "Die Berechnung ist sehr langsam"

**Lösungen:**
- Reduziere max_iterations für Vorschau-Rendering
- Implementiere Multi-Threading
- Nutze Periodizitätsprüfung und analytische Tests
- Rendere in niedrigerer Auflösung und skaliere hoch

---

## 10. Zusammenfassung: Die komplette Visualisierungspipeline

```
FÜR JEDEN PIXEL (x, y) IM FENSTER:
    
    1. MAPPING: Konvertiere Pixel zu komplexer Zahl
       c_real = min_real + (x / breite) × (max_real - min_real)
       c_imag = min_imag + (y / höhe) × (max_imag - min_imag)
    
    2. ITERATION: Teste ob c in der Menge liegt
       z_real = 0
       z_imag = 0
       iteration = 0
       
       SOLANGE iteration < max_iterations:
           // Berechne z² + c
           temp_real = z_real² - z_imag² + c_real
           temp_imag = 2 × z_real × z_imag + c_imag
           z_real = temp_real
           z_imag = temp_imag
           
           // Divergenz?
           WENN z_real² + z_imag² > 4:
               BREAK
           
           iteration++
    
    3. FÄRBUNG: Basierend auf Iterationszahl
       WENN iteration == max_iterations:
           farbe = SCHWARZ (in der Menge)
       SONST:
           farbe = berechne_farbe(iteration)
    
    4. ZEICHNE: Setze Pixel (x, y) auf farbe
```

---

## Viel Erfolg!

Die Mandelbrot-Menge ist ein faszinierendes mathematisches Objekt. Beim Hineinzoomen entdeckst du immer neue Strukturen – Spiralen, Seepferdchen-Täler, Mini-Kopien der gesamten Menge.

Ein paar abschließende Tipps:
- Beginne mit niedrigen max_iterations (50-100) für schnelle Tests
- Implementiere Zoom und Pan für interaktive Exploration
- Experimentiere mit verschiedenen Farbpaletten
- Speichere interessante Koordinaten, die du findest

Die Selbstähnlichkeit der Mandelbrot-Menge ist unendlich – du kannst beliebig tief zoomen und findest immer neue Details (bis zur Grenze der Gleitkomma-Präzision).
