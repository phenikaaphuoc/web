const observer = new IntersectionObserver((entries) => {
    entries.forEach((entry) => {
        const banner5 = document.querySelector('.nav');
        
        if (entry.isIntersecting) {
           
            banner5.style.transform = 'translateY(-100%)';
        } else {
            banner5.style.transform = 'translateY(0%)';
        }
    });
}); // Set threshold to 1.0 for each observed element

const hiddenElements = document.querySelectorAll('.banner2');

hiddenElements.forEach((el) => {
    observer.observe(el);
});

// Hide .banner5 initially and set opacity to 0
const banner5 = document.querySelector('.nav');
banner5.style.transform = 'translateY(100%)';


const mainImage = document.getElementById('mainImage');
const imageSources = ['qc1.png', 'qc2.jpg', 'qc3.jpg', 'qc4.jpg'];
let currentIndex = 0;



function changeImage() {
  currentIndex = (currentIndex + 1) % imageSources.length;


  mainImage.src = imageSources[currentIndex];
}


const interval = 3000;
setInterval(changeImage, interval);

