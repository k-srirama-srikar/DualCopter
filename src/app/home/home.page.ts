import { Component } from '@angular/core';
import { HttpClient} from '@angular/common/http';

@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage {

  public url = "198.162.1.0"

  constructor(private http:HttpClient) {

    
  }

 

  forward(){
    this.http.get(this.url+'/forward',{}).subscribe(res => {
      console.log(res);
    }, err => {
      console.log(err);
    });
    
  } 
  backward(){
    this.http.get(this.url+'/backward',{}).subscribe(res => {
      console.log(res);
    }, err => {
      console.log(err);
    });

  }
  right()
  {
    this.http.get(this.url+'/right',{}).subscribe(res => {
      console.log(res);
    }, err => {
      console.log(err);
    });
  }
  left()
  {
    this.http.get(this.url+'/left',{}).subscribe(res => {
      console.log(res);
    }, err => {
      console.log(err);
    });
  }
  up(){
    this.http.get(this.url+'/up',{}).subscribe(res => {
      console.log(res);
    }, err => {
      console.log(err);
    });
  }
  down(){
    this.http.get(this.url+'/down',{}).subscribe(res => {
      console.log(res);
    }, err => {
      console.log(err);
    });
  }
  manual()
  {
    this.http.get(this.url+'/manual',{}).subscribe(res => {
      console.log(res);
    }, err => {
      console.log(err);
    });
  }
  hover(){
    this.http.get(this.url+'/hover',{}).subscribe(res => {
      console.log(res);
    }, err => {
      console.log(err);
    });

  }
  stop(){
    this.http.get(this.url+'/stop',{}).subscribe(res => {
      console.log(res);
    }, err => {
      console.log(err);
    });
  }
  auto(){
    this.http.get(this.url+'/auto',{}).subscribe(res => {
      console.log(res);
    }, err => {
      console.log(err);
    });
  }

}
