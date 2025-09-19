program button
  use iso_c_binding
  implicit none
  ! Match the preprocessor definitions from wiring PI
  integer(c_int), parameter :: LOW = 0, HIGH = 0, OUTPUT = 1, INPUT = 0, &
       & PRESSED = 0, ledPin = 0, buttonPin = 1
  integer(c_int) :: ignore
  ! Set up the interfaces
    ! Next time I do fortran I will have a wrapper that grows to fit the needs
  ! in a /lib folder for good practice
  ! Define the interfaces with the header files
  interface
     ! wiringPiSetup(void)
     integer(c_int) function wiringPiSetup() bind(C, name="wiringPiSetup")
       use, intrinsic :: iso_c_binding
       ! This is the void setup function wrapped
     end function wiringPiSetup
     ! pinMode(int pin, int mode)
     subroutine pinMode(pin, mode) bind(C, name="pinMode")
       use, intrinsic :: iso_c_binding
       integer(c_int), value :: pin, mode
     end subroutine pinMode
     ! extern int digitalRead(int buttonPin)
     integer(c_int) function digitalRead(buttonPin) bind(C, name="digitalRead")
       use, intrinsic :: iso_c_binding
       integer(c_int), value :: buttonPin
     end function digitalRead
     ! extern int digitalWrite(int pin, int value);
     subroutine digitalWrite(pin, write_value) bind(C, name="digitalWrite")
       use, intrinsic :: iso_c_binding
       integer(c_int), value :: pin, write_value
     end subroutine digitalWrite
  end interface
  ! Set up circuit
  ignore = wiringPiSetup()
  call pinMode(ledPin, OUTPUT)
  call pinMode(buttonPin, INPUT)
  ! Control code
  button_control: do
     if (digitalRead(buttonPin) == PRESSED) then
        call digitalWrite(ledPin, HIGH)
        print *, "Button was pressed, LED is ON!"
     else
        call digitalWrite(ledPin, LOW)
        print *, "Button was released, LED is OFF!"
     end if
  end do button_control
  stop 0 ! No failure termination
end program button
