const die = (howManyTimes: number) => {
    for(let i = 0;i<howManyTimes;i++) {
        console.log("Kill me " + (i+1));
    }
};

die(10);
