int time = 10;
std::string greeting;
if (time < 12) {
  greeting = "Good morning";
}
else {
  greeting = "Good afternoon";
}
// greeting becomes "Good morning"


int time = 10;
std::string greeting = (time < 12) ? "Good morning" : "Good afternoon";